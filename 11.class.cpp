/*************************************************************************
	> File Name: 11.class.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年07月26日 星期日 21时11分44秒
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
    People(string name){
        cout << "parma constructor" << endl;
        this->name = name;
    }
    People(const People &a){
        cout << "copy constructor" << endl;
        this->name = a.name;
    }
private:
    string name;
};

People func(){
    People temp_a("hug");
    return temp_a;
}

int main(){
    People a = func();
    return 0;
}
