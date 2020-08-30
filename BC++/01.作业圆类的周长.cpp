/*************************************************************************
	> File Name: 01.作业圆类的周长.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年08月09日 星期日 18时53分24秒
 ************************************************************************/

#include<iostream>
using namespace std;

//设计类,求圆的周长
const double pi = 3.14;
class Circle{
public:
    double calculateZC(){
        return 2 * pi * m_R;
    }
    void set(int n){
        m_R = n;
        return ;
    }

    int m_R;
};

void test01(){
    Circle c1; //(圆类的对象)
    //c1.m_R = 10;
    c1.set(10);
    cout << "c1的周长 ：" << c1.calculateZC();
}


int main(){
    test01();
    return 0;
}
