/*************************************************************************
	> File Name: 13.const的引用.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年08月09日 星期日 17时34分12秒
 ************************************************************************/

#include<iostream>
using namespace std;

void test01(){
    //int &ref = 10;//引用不合法的内处，不可以
    const int &ref = 10; //加入const后，编译器处理方式为：引入临时变量int tmp = 10; const int &ref = tmp;
    int *p = (int *)&ref; //用指针修改const
    *p = 1000;
    cout << "ref = " << ref << endl;
}
//const引用使用场景， 用来修饰形参
void test02(const int &s){
  //  s++;    const修饰不可改变的值
    cout << s << endl;
}

int main(){
    test01();
    int a = 10;
    test02(a);

    return 0;
}
