/*************************************************************************
	> File Name: 287.OJ.set.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年07月23日 星期四 18时50分11秒
 ************************************************************************/

#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
#include<set>
#include<cstdlib>
using namespace std;

typedef pair<int, int> PII;
int main(){
    int n, a, t = 0, sum = 0;
    cin >> n;
    set<PII> s;
    for(int i = 0; i < n ; i++){
        cin >> a;
        s.insert(PII(a, t++));
    }
    for(int i = 0; i < n - 1; i++){
        int a = s.begin()->first;
        s.erase(s.begin());
        int b = s.begin()->first;
        s.erase(s.begin());
        sum += a + b;
        s.insert(PII(a + b, t++));
    }
    return 0;
}
