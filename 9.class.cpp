/*************************************************************************
	> File Name: 9.class.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年07月26日 星期日 18时15分03秒
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
    People(){
        arr = new int[10];
        cout << "default constructor" << endl;
    }
    ~People(){
        delete arr;
        cout << "delete" << endl;
    }
    int *arr;
};

int main(){
    People a;
    a.arr[9] = 18;
    cout << "hello world" << endl;
    return 0;
}


