/*************************************************************************
	> File Name: 18.class.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年08月01日 星期六 15时13分32秒
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
struct A{
    int x;
};
struct B : virtual public A{
    void set(int x){
        this->x = x;
        cout << "set:" << &this->x << endl;
    }
};
struct C: virtual public A{
    int get() {
        cout << "get:" << &this->x << endl; 
        return this->x;
    }
};

struct D : public B, public C{};

int main(){
    D d;
    d.set(9973);
    cout << sizeof(d) << endl;
    cout << d.get() << endl;

    return 0;
}
