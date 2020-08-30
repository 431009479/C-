/*************************************************************************
	> File Name: 03_namespace的使用.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年08月05日 星期三 07时54分54秒
 ************************************************************************/

#include<iostream>
using namespace std; //namespace命名空间主要用途 用来解决命名冲突的问题


//1、命名空间 可以方函数，变量，结构体， 类， 等。
//2、命名空间必须定义在全局领域下
namespace A{
    void func();
    int m_a = 20;
    struct Person{

    };
    class Animal{};

    namespace B{
        int m_a = 10;
    }
}


//3、命名空间可以嵌套命名空间
void test02(){
    cout << "命名空间 B下的m_a :" << A::B::m_a << endl;
}

//4、命名空间是开放的，可以随时往原来的命名空间添加内容
namespace A{ //此命名空间A会和上面A命名空间合并
    int m_b = 100;
}

void test03(){
    cout << "A::下的m_a :" << A::m_a << ",A::下的m_b" << A::m_b << endl;
}



//5、命名空间可以起别名
namespace veryLongName{
    int m_a = 100; 
}

void test04(){
    namespace verylongname = veryLongName;
    cout <<"veryLongName : "<< veryLongName::m_a << endl;
    cout <<"verylongname : "<< verylongname::m_a << endl;
}



int main(){

    test02();
    test03();
    test04();



    return 0;
}
