/*************************************************************************
	> File Name: func.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年08月08日 星期六 16时39分02秒
 ************************************************************************/

#include<iostream>
#include<functional>
using namespace std;

class A{
public:
    void operator()(int ){
        cnt++;
       f() 
    }
    
private:
    int cnt = 0;
}
void f(function<int>(int, int) > g){
    cout << g(3, 4) << endl;
    return;
}


int main(){
    f


    return 0;
}
