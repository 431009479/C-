/*************************************************************************
	> File Name: 19.class.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年08月23日 星期日 23时00分57秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#include <functional>
using namespace std;

template<typename T>
void my_swap(T &&a, T &&b) {
    typename remove_reference<T>::type c;
    c = a;
    a = b;
    b = c;
    return ;
}

//move
template<typename T>
typename remove_reference<T>::type my_move(T &&a) { //&& 接收引用，左值变量会被推导为左值引用类型，右值会被推导为普通类型
    return typename remove_reference<T>::type(a); //C++ 中的强转 类型(变量)
}

void func(int &a) {
    cout << "left value" << endl;
}

void func(int &&a) {
    cout << "right value" << endl;
}

int main() {
    int a = 123, b = 456;
    cout << a << " " << b << endl;
    my_swap(a, b);
    cout << a << " " << b << endl;
    my_swap(my_move(a), my_move(b));
    cout << a << " " << b << endl;
    func(a);
    func(my_move(a));
    return 0;
}

