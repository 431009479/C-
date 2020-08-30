/*************************************************************************
	> File Name: max.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年08月06日 星期四 14时06分18秒
 ************************************************************************/

#include<iostream>
using namespace std;
namespace haizei{

class A{
public:
    template<typename T, typename U>
    void operator()(const T &a, const U &b){
        cout << a + b << endl;
    }
};

}

int main(){
    haizei::A k;
    k(3.8, 4.5);
    return 0;
}
