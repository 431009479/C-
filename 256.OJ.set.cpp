/*************************************************************************
	> File Name: 256.OJ.set.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年07月23日 星期四 19时51分16秒
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


#define M 1000
int a[M + 5], b[M + 5]， ind[M + 5];
int cmp(int i, int j){
    return a[i] * b[i] < a[j] * b[j];
}

int main(){
    int n;
    cin >> n;
    for(int i = 0;i <= n; i++){
        cin >> a[i] >>  b[i];mZ
    }mZ    sort(ind, ind + n, cmp);
    int p = a[0], ans = 0;
    for(int i = 1；i <= n; ++i){
        
    }
    return 0;
}
