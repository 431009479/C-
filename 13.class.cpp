/*************************************************************************
	> File Name: 13.class.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年07月27日 星期一 19时22分23秒
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

class Point {
public :
    Point() :__x(0), __y(0){}
    Point(int x, int y) :__x(x), __y(y){}
    int x() const {return __x;}
    int y() const {return __y;}
    Point operator+(const Point &a){
        return Point(x() + a.x(), y() + a.y());
    }
    Point &operator+=(const Point &a){
        this->__x += a.x();
        this->__y += a.y();
        return *this;
    }
    Point &operator++(){ 
        __x += 1;
        __y += 1;
        return *this;
    }
    Point operator++(int){ //区分前++ 和后++（int）
        Point temp(*this);
        __x += 1;
        __y += 1;
        return temp;
    }

private:
    int __x, __y;
};

ostream &operator<<(ostream &out, const Point &a){
    out <<"Point (" << a.x() << "," << a.y() << ")";
    return out;
}

int main(){
    Point a(4, 5), b(3, 4),c(1, 1);
    cout << a << " "  << b<<" " << c << endl;
    cout << a + b << endl;
    cout << "pre incr : " << ++(c += b) << endl;
    cout << c << endl;
    cout << "after incr : " << c++ << endl;
    cout << c << endl;
    return 0;
}
