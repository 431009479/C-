/*************************************************************************
	> File Name: 34.thread_pool.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年08月13日 星期四 16时09分00秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<thread>
#include<functional>
#include<mutex>
#include<condition_variable>
using namespace std;

class Task{
public:
    template<typename T, typename ...ARGS>
    Task(T func, ARGS... args){
        this->func = bind(func, forward<ARGS>(args)...);
    }
    void run(){
        this->func();
    }
    void operator()(){
        this->func();
    }

private:
    function<void()>func;
};
/*-------------------------------------------------------*/
class ThreadPool{
public:
    ThreadPool(int n = 5): 
    is_running(false), max_thread_num(n),
    m_mutex(), m_cond(){}

    void start(){
        unique_lock<mutex> lock(m_mutex);
        if(is_running) return ;
        is_running = true;
        for(int i = 0; i < max_thread_num ; i++){
            threads.push_back(new thread(&ThreadPool::thread_loop, this));
        }
    }

    void __stop_set_false(){
        unique_lock<mutex> lock(m_mutex);
        is_running = false;
        m_cond.notify_all();
    }
    void stop(){
        __stop_set_false();
        for(int i = 0; i < this->max_thread_num; i++){
            threads[i]->join();
            delete threads[i];
        }
        threads.clear();
    }
    void thread_loop(){
        while(is_running){
            Task *t = get_one_task();
            if(t != nullptr){
                cout << "thread_loop tid : " << this_thread::get_id() << endl;
                t->run();
            }
        }
    }
    
    Task *get_one_task(){
        unique_lock<mutex> lock(m_mutex);
        while(Tasks.empty() && is_running){
            m_cond.wait(lock);
        }
        Task *t = nullptr;
        if(!Tasks.empty() && is_running){
            t = Tasks.front();
            Tasks.pop();
        }
        return t;
    }
template<typename Func_T, typename ...ARGS>
void add_one_task(Func_T f, ARGS...args){
    __add_one_task(new Task(f, forward<ARGS>(args)...));
}
    void __add_one_task(Task *t){
        unique_lock<mutex> lock(m_mutex);
        Tasks.push(t);
        m_cond.notify_one();
    }

    ~ThreadPool(){ stop(); }
private:
    bool is_running;
    int max_thread_num;
    vector<thread *> threads;
    queue<Task *> Tasks;
    mutex m_mutex;
    condition_variable m_cond;
};
/*-------------------------------------------------------*/

void func(int x, int &n){
    n += 2;
    cout << "func : " << x << " " << n << endl;
}

int main(){
  int n = 123;
    Task t(func, 23, ref(n));
    t.run(); t();
    cout << n << endl;
    ThreadPool tp(3);
    tp.start();
    for(int i = 0; i < 10; i++){
        tp.add_one_task(func, i, ref(n));
    }
    cout << "add task done" << endl;
    this_thread::sleep_for(chrono::seconds(2));
    cout << "tp stop" << endl;
    return 0;
}
