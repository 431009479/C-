/*************************************************************************
	> File Name: 8.class.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年07月25日 星期六 16时19分49秒
 ************************************************************************/

#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
#include<cstdlib>
using namespace std;

class People{
    friend int main();//友元函数
    int x, y;
public:
    void set(int x);
    void say();
};

void People::set(int x){
    cout << "set function :" << this << endl;
    this->x = x;
}

void People::say(){
    cout << x << " " << y << endl;
}

struct People2{
    int x, y;
};

int main(){
    People a;
    People2 b;
    a.set(3);
    a.y = 12345;
    cout << "a object:" << &a << endl;
    b.x = 4;
    a.say();
    cout << b.x << endl;
    return 0;
}
