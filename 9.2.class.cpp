/*************************************************************************
	> File Name: 9.2.class.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年07月26日 星期日 18时23分09秒
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
public:
    People() = default;//限制默认函数的生成

  //  People() = delete; //函数被delete过了，那么重载该函数也是非法的，该函数我们习惯上称为删除函数。
    People(string name){
        this->name = name;
    }
    People(int x){
        cout << "int parm constructor";
        this->x = x;
    }
    People(const People &a){
        this->name = a.name;
        this->x = x;
    }
    void operator=(const People &a){
        cout << "operator=" << endl;
        this->name = a.name;
        this->x = a.x;
    }
    ~People(){
        cout << "delete" << endl;
    }
    string name;
    int x;
};

int main(){
    People a = string("xiong");
    People d("dong");
    People b = 678;
    People c(123);
    cout << a.name << " " << d.name << endl;
    cout << c.x << " " << b.x << endl;
    c = 987;
    a = 111;
    cout << c.x << endl;
    People e = a;
    cout << e.name << " " << e.x << endl;
    c = a;
    cout << c.name << " " << c.x << endl;
    return 0;
}


