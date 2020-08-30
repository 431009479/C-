/*************************************************************************
	> File Name: 11_参数的传递方法.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年08月06日 星期四 08时07分03秒
 ************************************************************************/

#include<iostream>
using namespace std;

void mySwap01(int a, int b){
    int temp = a;
    a = b;
    b = temp;
    cout << "mySwap01::a : " << a << " ";
    cout << "mySwap01::b : " << b << endl;
}

void mySwap02(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
    cout << "mySwap02::a : " << *a << " ";
    cout << "mySwap02::b : " << *b << endl;
}

void mySwap03(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
    cout << "mySwap03::a : " << a << " ";
    cout << "mySwap03::b : " << b << endl;
}

void test(int a, int b){
    cout << "a : " << a << " ";
    cout << "b : " << b << endl;
}

//引用注意事项
//1、引用必须引一块合法的内存空间
//int &a = 10;
//2、不要返回局部变量的引用， 可以以下代码：
int &doWork(){
    static int a = 10;
    return a;
    //如果函数返回值是引用，那么函数的调用可以作为左值
}
//引用的本质焦是一个指针常量
int main(){
    int a =10;
    int b = 20;
    int &p = a;
    p = 50;
    cout << a << endl;
    mySwap01(a, b);
    test(a, b);
    mySwap02(&a, &b);
    test(a, b);
    mySwap03(a, b);
    test(a, b);

    return 0;
}
