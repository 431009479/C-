/*************************************************************************
	> File Name: 16.class.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年07月28日 星期二 19时55分41秒
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
class D{
public :
    D(){ cout << "D constructor" << endl; }
    ~D(){
        cout << "D destructor" << endl;
    }
};

class A{
public :
    A() = delete;
    A(int x, int y) {cout <<"A constructor" << endl;}  
    ~A(){
        cout << "A destructor" << endl;
    }
};

class B{
public:
    B() {cout <<"B constructor" << endl;}
    ~B(){
        cout << "B destructor" << endl;
    }
};

class C : public D{
public:
   // C() {cout << "C constructor";}
    C() : a(3, 4) {cout << "C constructor" << endl;}
    ~ C(){
        cout << "C destructor" << endl;
    }
private:
    A a;
    B b;
};

int main(){
    C c;
    return 0;

    return 0;
}
