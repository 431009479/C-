/*************************************************************************
	> File Name: singleton.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年08月22日 星期六 16时08分08秒
 ************************************************************************/

#include<iostream>
#include<mutex>
using namespace std;

class Singleton{
public:
    static Singleton *init(){
        if(single == nullptr){
            unique_lock<mutex> lock(m_mutex);
            if(single == nullptr){
                single =  new Singleton();
                return single;
            }
        }
        return nullptr;
    }
private:
    static Singleton *single;
    static std::mutex m_mutex;
    Singleton() = default;
    Singleton(const Singleton&) = default;
    ~Singleton() {}
};
Singleton *Singleton::single = nullptr;
mutex Singleton::m_mutex;

int main(){
    Singleton *p = Singleton::init();



    return 0;
}
