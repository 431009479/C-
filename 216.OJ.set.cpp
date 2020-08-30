/*************************************************************************
	> File Name: 216.OJ.set.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年07月23日 星期四 18时27分34秒
 ************************************************************************/

#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
#include <map>
#include <set>
#include<cstdlib>
using namespace std;

typedef pair<string, int> PIR;

int main(){

    set<PIR> s;
    string name;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> name;
        name = name.substr(name.find(".") + 1, name.size());
        s.insert(PIR(name, i));
    }

    for(auto iter = s.begin(); iter != s.end(); iter++){
        cout << iter->first << endl;
    }

    return 0;
}
