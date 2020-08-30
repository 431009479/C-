/*************************************************************************
	> File Name: 26.nullptr.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年08月02日 星期日 20时06分33秒
 ************************************************************************/

#include<iostream>
using namespace std;
int f(int x){
    cout << "output int value :";
    cout << x << endl;
    return 0;
}

int f(int *x){
    cout << " output_address : ";
    cout << x << endl;
    return 0;
}

int main(){
   // cout << nullptr << endl;
    printf("%lld\n", (long long)nullptr);
    cout << NULL << endl;
    int n = 123, *p = &n;
    f(n);
    f(p);
    f(nullptr); //地址
    f(int(NULL)); //把0当成地址, (void *)0
    return 0;
}
