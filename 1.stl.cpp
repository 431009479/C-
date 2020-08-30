/*************************************************************************
	> File Name: 1.stl.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年07月21日 星期二 19时51分51秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
using namespace std;

/*int main(){
    int op, val;
    queue<int> q;
    while( cin >> op >> val ){
        switch(op){
            case 1: q.push(val);break;
            case 2: q.pop();break;
            case 3: cout << q.front() << endl; break;
        }
        cout << "queue size:" << q.size() <<",empty :" << (q.empty() ? "true" : "flags") << endl;
        printf("queue size: %lu ,empty : %s\n", q.size(), q.empty() ? "true" : "flags");
    }

    return 0;
}*/
/*int main(){
    string s1 = "hello", s2 = "world";

    s1 += " ";
    s1 += s2;
    cout << s1 << endl;
    for(int i = 0; i < int(s1.size()); i++){
        cout << s1[i];
    }
    return 0;
}*/

int main() {
	string input;
    cin >> input;
	cout << input << endl;
    cout << input.length() << endl;
    cout << input[0] << endl;
    string str = "yangzhou301";
    auto result = input + str; //自动类型推导
    cout << result << endl;
    cout << (result < str) << endl;
    return 0;
}
