/*************************************************************************
	> File Name: 3.sort.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年07月21日 星期二 20时53分51秒
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


struct CMP_FUNC{
    bool operator()(int a, int b){
        return a > b;
    }
};

int main(){
    int arr[1000], n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    nth_element(arr, arr + 1, arr + n);
    cout << arr[1] << endl;
   // sort(arr, arr + n, CMP_FUNC());
    sort(arr, arr + n, [](int a, int b)-> bool {return a > b;});
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }


    return 0;
}
