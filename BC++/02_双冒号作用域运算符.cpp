/*************************************************************************
	> File Name: 02_双冒号作用域运算符.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年08月05日 星期三 07时49分18秒
 ************************************************************************/

#include<iostream>
using namespace std;

int atk = 200;

void test01(){

    int atk = 100;
    cout << "atk : " << atk << endl;

    cout << "::atk : " << ::atk<< endl;//全局作用域 直接加::
}

int main(){
    test01();

    return 0;
}
