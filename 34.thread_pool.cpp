/*************************************************************************
	> File Name: 34.thread_pool.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年08月13日 星期四 16时09分00秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<queue>
#include<thread>
#include<functional>
#include<mutex>
#include<condition_variable>
#include<map>
using namespace std;

class Task{
public:
    template<typename T, typename ...ARGS>
    Task(T func, ARGS... args){
        this->func = bind(func, forward<ARGS>(args)...);
    }
    void operator()(){
        this->func();
        return ;
    }

private:
    function<void()>func;
};


class ThreadPool{
public:
    ThreadPool(int n = 5): max_thread_num(n), m_mutex(), m_cond(){}
    void start(){
        for(int i = 0; i < max_thread_num ; i++){
            threads.push_back(new thread(&ThreadPool::worker, this));
        }
    }
    void worker(){
        thread::id id = this_thread::get_id();
        is_running[id] = true;
        while(is_running[id]){
            Task *t = getOneTask();
            (*t)();
            delete t;
        }
        return ;
    }

    void stop(){
         this_thread::sleep_for(chrono::seconds(2));
        for(int i = 0; i < max_thread_num; i++){
            addOneTask(&ThreadPool::stop_task, this);
        }
        for(int i = 0; i < this->max_thread_num; i++){
            threads[i]->join();
            delete threads[i];
        }
        threads.clear();
        return;
    }

    template<typename T, typename ...ARGS>
    void addOneTask(T func, ARGS...args){
        unique_lock<mutex> lock(m_mutex);
        task_queue.push(new Task(func, forward<ARGS>(args)...));
        m_cond.notify_one();
        return ;
    }

    //非线程安全的临界资源: 多线程对同一资源进行争夺,操作.从而出错;
    //原子操作:不可分割的操作
    
private:
    void stop_task(){
        thread::id id = this_thread::get_id();
        is_running[id] = false;
        return ;
    }
    Task *getOneTask(){
        unique_lock<mutex> lock(m_mutex);//抢碗-->资源
        while(task_queue.empty()) {//等待,队列中任务
            //使用while循环是：可能存在等待任务的进程接收信号但没有任务队列是空,可能刚添加的任务，被其他线程拿走了。
            m_cond.wait(lock);           
        }
        Task *t = task_queue.front();
        task_queue.pop();
        return t;
    }
    int max_thread_num;
    vector<thread *> threads;
    queue<Task *> task_queue; 
    map<thread::id, bool> is_running;
    mutex m_mutex;
    condition_variable m_cond;
};

void thread_func1(int a, int b){
    cout << a << " + "<< b << " = " << a + b << endl;
    return ;
}
int is_prime(int x){
    if(x <= 1) return 0;
    for(int i = 2; i * i <= x; i++){
        if(x % i == 0) return 0;
    }
    return 1;
}


int cnt = 0;
void task_func(int l, int r){
    for(int i = l; i <= r; i++){
        if(is_prime(i))__sync_fetch_and_add(&cnt, 1);
    }
    
    return ;
}

int main(){
    int n = 100;

    ThreadPool tp(6);
    tp.start();
    for(int i = 0, j = 1; i< 5; i++, j += 200000){
        tp.addOneTask(task_func, j, j + 200000 - 1);
    }
    tp.stop();
    cout << cnt << endl;
    return 0;
}
