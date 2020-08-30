/*************************************************************************
	> File Name: 20.class.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年08月01日 星期六 15时51分06秒
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
class Animal{
public:
    virtual void runI(){
        cout << "I don't konw how to run" << endl;
    }
};

class Cat :public Animal{
public :
    void runI() override{
        cout << "I can run whit four legs" << endl;
    }
};

class Dog :public Animal{
public:
    void runI()override{
        cout << "I can run with four legs, tail yao a yao" << endl;
    }
};
class Bat :public Animal{
public:
    void runI()override{
        cout << "I can fly!" << endl;
    }
};

class A{
public :
    A() = default;
    A(string s) {
        cout << "param constructor" << endl;
    }
    A(const A &a) {
        cout << "copy constructor" << endl;
    }
    int x;
    virtual void say(int xx){
        cout << this << endl;
        cout << "Class A : I can say, x = " << xx << ", this->" << this->x << endl;
    }
};



typedef void (*func)(void *, int);

A retA() {
    A temp_a("hello world");
    return temp_a;
}

class Base{
public:
    Base(){
        cout << "Base constructor" << endl;
        this-> x = new int;
    }
    virtual ~Base(){
        cout<< "Base destructor" << endl;
        delete [] this->x;
    }
private:
    int *x;

};

class Base_A :public Base{
public:
    Base_A(){
        cout << "Base_A constructor" << endl;
        this->y = new int;
    }
    ~Base_A(){
        cout << "Base_A destructor" << endl;
        delete this->y;
    }
private:
    int *y;
};

int main(){
    Base *ba = new Base_A();
    delete ba;

    cout << sizeof(A) << endl;
    A temp_a, temp_b;
    temp_a.x = 9973;
    temp_b.x = 10000;
    ((func **)(&temp_a))[0][0](&temp_b, 6);

    srand(time(0));
    Cat a;
    cout << sizeof(Cat) << endl;
    Animal k;
    Animal &b = a;
    Animal *c[10];
    a.runI();
    b.runI();
    k.runI();

    for(int i = 0; i < 10; i++){
        int n = rand() % 3;
        switch(n){
            case 0: c[i] = new Cat(); break;
            case 1: c[i] = new Dog(); break;
            case 2: c[i] = new Bat(); break;
        }
    }
    for(int i = 0; i < 10; i++){
        c[i]->runI();
    }
    return 0;
}
