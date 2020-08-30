/*************************************************************************
	> File Name: 30.function.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年08月08日 星期六 15时26分12秒
 ************************************************************************/

#include<iostream>
#include <functional>
using namespace std;

namespace haizei {

template<typename RT, typename ...PARAMS> 
class base {
public :
    virtual RT operator()(PARAMS...) = 0;
    virtual base<RT, PARAMS...>* getCopy() = 0;
    virtual ~base() {}
};

template<typename RT, typename ...PARAMS> 
class normal_func : public base<RT, PARAMS...> {
public :
    typedef RT (*func_type)(PARAMS...);
    normal_func(func_type func) : ptr(func) {}
    virtual RT operator()(PARAMS...args) override {
        return this->ptr(args...);
    }
    virtual base<RT, PARAMS...> *getCopy()override{
        return new normal_func<RT, PARAMS...>(ptr);
    }
private:
    func_type ptr;
};

template<typename C, typename RT, typename ...PARAMS> 
class functor : public base<RT, PARAMS...> {
public :
    functor(C &func) : ptr(func) {}
    virtual RT operator()(PARAMS...args) override {
        return this->ptr(args...);
    }

    virtual base<RT, PARAMS...> *getCopy(){
        return new functor<C, RT, PARAMS...>(ptr);
    }
private:
    C &ptr;
};


template<typename RT, typename ...PARAMS> class function;
template<typename RT, typename ...PARAMS>
class function<RT(PARAMS...)> {
public :
    function(RT (*func)(PARAMS...)) 
    : ptr(new normal_func<RT, PARAMS...>(func)) {}


    template<typename T>
    function(T a) 
    : ptr(new functor<typename remove_reference<T>::type, RT, PARAMS...>(a)){}

    RT operator()(PARAMS... args) {
        return this->ptr->operator()(args...);
    }
    function(const function &f) {
        this->ptr = f.ptr->getCopy();
    }
    function(function &&f) {
        this->ptr = f.ptr;
        f.ptr = nullptr;
    }

     ~function() {
     //   cout << "haizei dalete" << endl;
        delete ptr;
    }

private:
    base<RT, PARAMS...> *ptr;
};

} // end of haizei






void f(function<int(int, int)> g) {
    cout << g(3, 4) << endl;
    return ;
}

int add(int a, int b) {
    return a + b;
}

struct MaxClass {
    int operator()(int a, int b) {
        return a > b ? a : b;
    }
};
template<typename RT, typename ...ARGS> class FunctionCnt;
template<typename RT, typename ...ARGS>
class FunctionCnt<RT(ARGS...)>{
public:
    FunctionCnt(haizei::function<RT(ARGS...)> __g) : g(__g), __cnt(0){}
    RT operator()(ARGS ...args) {
        __cnt ++;
        return g(args...);
    }
    int cnt(){return __cnt;}
private:
    haizei::function<RT(ARGS...)>g;
    int __cnt;
};

int main() {
    MaxClass max;
    f(add);
    f(max);
    haizei::function<int(int, int)> g1(add);
    haizei::function<int(int, int)> g2(max);
    cout << g1(3, 4) << endl;
    cout << g2(3, 4) << endl;
    FunctionCnt <int(int, int)>add_cnt(add);
    add_cnt(3, 5);
    add_cnt(4, 6);
    add_cnt(8, 9);
    cout << add_cnt.cnt();
    return 0;
}
