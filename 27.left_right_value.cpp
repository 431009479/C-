/*************************************************************************
	> File Name: 27.left_right_value.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年08月02日 星期日 20时24分31秒
 ************************************************************************/

#include<iostream>
using namespace std;

#define TEST(a, f){\
    cout << #a << " : " << #f << " "; \
    f(a);\
}

void f2(int &x){
    cout << "left value" << endl;
}

void f2(int &&x){
    cout << "right value" << endl;
}


void f(int &x){
    cout << "left value" << endl;
    TEST(x, f2);
}
void f(int &&x){
    cout << "right value" << endl;
    TEST(move(x), f2);
    TEST(forward<int &&>(x), f2);
}

int test_func(const int &x){
    cout << x << endl;
    return 0;
}

/*int test_func1(const int &&x){
    cout << x << endl;
    return 0;
}*/

int main(){
    int a, b = 1, c = 3;
    (++a) = b + c;
    cout << a << endl;
    (a++);
    (a = b) = c;
    cout << a << "," << b << endl;
    int arr[10];
    arr[3] = 12;
    (a += 3) = 67;
    cout << a << endl;
    TEST(a += 3, f);
    TEST(1 + 4, f);
    TEST(b + c, f);
    TEST(a++, f);
    TEST(++a, f);
    test_func(123);
   // test_func1(a);
    return 0;
}
