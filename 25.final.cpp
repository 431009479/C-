/*************************************************************************
	> File Name: final.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年08月02日 星期日 19时49分04秒
 ************************************************************************/

#include<iostream>
#include<map>
using namespace std;
class A : public map<int, int>{
public:
    virtual void say(){
        cout << "Class A :hello world" << endl;
    }
};

class B final: public A{ // final 限制继承B类
public:
    void say() final override{
        cout << "Class B : hello world" << endl;
    }
};

/*class C: public B{
public :
     void say() override{ //final 限制重写B类中 say()方法
        cout << "Class : hello world" << endl;
    }
};*/





int main(){
    A a;
    a[12131] = 1133;
    a[712454355] = 9973;
    for(auto x : a){
        cout << x.first << " " << x.second << endl;
    }

    return 0;
}
