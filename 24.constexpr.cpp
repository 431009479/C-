/*************************************************************************
	> File Name: 24.constexpr.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年08月02日 星期日 18时57分21秒
 ************************************************************************/

#include<iostream>
using namespace std;


constexpr int f(int x){
    return 3 * x * x + x;
}

class A{
public :
    constexpr A(int x, int y): x(x), y(y){}
    int x, y;
};

int main(){
    const int n = 123; //const运行期
    int a;
    cin >> a;
    const int b = 2 * a;
    cout << n << endl;
    cout << b << endl;
    constexpr int c = 2 * n; //constexpr 编译期常量
//  constexpr int c = 2 * a;
    constexpr int d = f(12);
    cout << f(5) << endl;
    constexpr A k(2, 3);
    cout << k.x << "," << k.y << endl;
    return 0;
}
