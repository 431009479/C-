/*************************************************************************
	> File Name: 15.iscceed.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年07月28日 星期二 18时52分30秒
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
class Alnimal {
public:
    Alnimal(string name, int age) : __name(name), age(age){}
    void say(){
        cout << "my name is : " << __name  << ",my age is : "<< age << endl;
    }

protected:
    string __name;
private:
    int age;
};

class Cat :public Alnimal{
public:
    Cat() = delete;
    Cat(string name, int age) : Alnimal(name, age){}
};

class Bat :protected Alnimal{
public:
    Bat() = delete;
    Bat(string name, int age) : Alnimal(name, age){}
    void say(){
        Alnimal::say();
        cout << "class Bat : " << __name << endl;
       // cout << "class Bat : " << age << endl;
    }
};

int main(){
    Cat a("kitty", 29);
    a.say();
    Bat b("hug", 16384);
    b.say();
    return 0;
}

