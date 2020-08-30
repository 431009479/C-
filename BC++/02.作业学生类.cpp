/*************************************************************************
	> File Name: 02.作业学生类.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年08月09日 星期日 19时06分10秒
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;

//设计类，属性：姓名， 年龄。
//可以给年龄，姓名赋值，也可以显示学生的姓名和年龄。

class Stude{
public:
    void set(char *str, int n){
        strcpy(name, str);
        age = n;
        return ;
    }
    void get(){
        cout <<"姓名 : " << name << ",年龄 ：" << age << endl;
    }

private:
    char name[20];
    int age;
};

void test01(){
    Stude stu;
    char name[20] ="xiongdongdong";
    stu.set(name, 20);
    stu.get();
    return ;
}


int main(){
    test01();


    return 0;
}
