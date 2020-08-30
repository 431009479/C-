/*************************************************************************
	> File Name: 12.指针的引用.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年08月09日 星期日 17时20分39秒
 ************************************************************************/

#include<iostream>
using namespace std;


struct Person{
    int m_Age;
};
void allocatMemory(Person **p){//**p 具体的Person对象 *p对象指针 p指针的指针
    *p = (Person *)malloc(sizeof(Person));
    (*p)->m_Age = 100;
}

void test01(){
    Person *p = NULL;
    allocatMemory(&p);
    cout << "P的年龄 ：" << p->m_Age << endl; 
}

void allocatMemoryByRef(Person * &p){ //指针的引用
    p = (Person *)malloc(sizeof(Person));
    p->m_Age = 100;
}

void test02(){
    Person *p = NULL;
    allocatMemoryByRef(p);
    cout << "p的年龄 ：" << p->m_Age << endl;
}

int main(){

    test01();
    test02();
    return 0;
}
