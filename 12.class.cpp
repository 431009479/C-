/*************************************************************************
	> File Name: 12.class.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年07月27日 星期一 18时29分19秒
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

namespace haizei {

class istream{
public:
    istream &operator>>(int &n){
        std::cin >> n;
        return *this;
    }
private:

};

class ostream{
public:

    ostream &operator<<(int &n){
        std::cout << n;
        return *this;
    }
    ostream &operator=()
    ostream &operator<<(const char *mag){
        std::cout << mag;
        return *this;
    }
private:
    

};
    istream cin;
    ostream cout;
};

haizei::ostream &operator<<(haizei::ostream &out, double &z){
    std::cout << z;
    return out;
}

ostream &operator+(ostream &out, const int &x){
    cout << x;
    return out;
}
int main(){
    int n, m;
    haizei::cin >> n >> m;
    haizei::cout << n << " " << m << "\n";
    double k = 5.6;
    haizei::cout << k << "\n";
    cout + 8 + 9 + 10;
    return 0;
}
