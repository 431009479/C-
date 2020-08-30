/*************************************************************************
	> File Name: sort.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年08月17日 星期一 14时42分29秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;

namespace haizei{
template<typename T>
    struct greater{
        bool operator()(const T &a, const T &b){
            return a > b;
        }
    };
}


int main(){
    srand(time(0));
    int arr[10];
    for(int i = 0; i < 10; i++){
        arr[i] = rand() % 10;
    }
    sort(arr, arr + 10, haizei::greater<int>());
    for(int i = 0; i < 10; i++){
        cout << arr[i] << " ";
    }


}
