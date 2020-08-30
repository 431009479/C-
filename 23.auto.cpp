/*************************************************************************
	> File Name: 23.auto.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年08月02日 星期日 18时40分16秒
 ************************************************************************/

#include<iostream>
#include<map>
using namespace std;



int main(){
    auto a = 123;
    cout << sizeof(a) << endl;
    map<int, int> arr;
    arr[676556] = 1267886;
    arr[999] = 10000;
    arr[45678] = 712;
    for(auto iter = arr.begin(); iter != arr.end(); iter++){
        cout << iter->first << " " << iter->second << endl;
    }
    for(auto x : arr){
        cout << x.first << "," << x.second << endl;
    }


    return 0;
}
