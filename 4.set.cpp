/*************************************************************************
	> File Name: 4.set.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年07月23日 星期四 18时13分55秒
 ************************************************************************/

#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
#include<cstdlib>
#include<set>
using namespace std;

int main(){
    set<int> s;
    s.insert(345);
    s.insert(5);
    s.insert(123);
    s.insert(1000);
    cout << s.size() << endl;
    s.insert(123); //insert 添加
    cout << s.size() << endl;
    cout << *(s.begin()) << endl; //begin 迭代器
    for(auto  iter = s.begin(); iter != s.end(); iter++){
        cout << *iter << endl;
    }
    s.erase(s.begin()); //erase 删除
    cout << *s.begin() << endl;
    return 0;
}
