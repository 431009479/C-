/*************************************************************************
	> File Name: 10_引用的基本.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年08月06日 星期四 07时39分56秒
 ************************************************************************/

#include<iostream>
using namespace std;
//1、Type &别名 = 原名
void test01(){
    int a = 10;
    int &b = a;
    b = 100;
    cout << " a = :" << a << endl;
    cout << " b = :" << b <<endl;
}

//2、引用必须初始化
void test02(){
    int a = 10;

    
   // int &b; //初始化
    int &b = a; //引用初始化后不可以修改
    int c = 100;
    b = c; //赋值
}
//3、对数组建立引用
void test03(){
    int arr[10];
    for(int i = 0; i < 10; i++){
        arr[i] = i;
    }
    //给数组起别名
    int(&Parr)[10] = arr;
    for(int i = 0; i < 10; i++){
        cout << Parr[i] << " ";
    }
    cout << endl;
    //另一种方法
    typedef int(ARR)[10];
    ARR &Parr2 = arr;
    for(int i = 0; i < 10; i++){
        cout << Parr2[i] << " " ;
    }
    cout << endl;

}



int main(){
    test01();
    test02();
    test03();
    return 0;
}
