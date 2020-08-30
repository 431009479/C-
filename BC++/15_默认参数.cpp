/*************************************************************************
	> File Name: 15_默认参数.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年08月09日 星期日 20时00分45秒
 ************************************************************************/

#include<iostream>
using namespace std;

// 函数参数可以有默认值
// 如果有一个位置有了默认值, 那么从这个位置开始,从左往右都必须有默认值。
//声明 和 实现只能有一个有默认值

//void func(int a = 10, int b, int c) 这样是错误的。

void func(int a, int b = 10, int c = 1){
    cout << "a + b + c : " << a + b + c << endl;
    return;
}
//void func1(int a = 10, int b = 20);
//void func1(int a = 10, int b = 20){} //这样是错误的


void test01(){
    func(1, 2); //2会赋值给b；

    return ;
}


int main(){
    test01();
    return 0;
}
