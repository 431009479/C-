/*************************************************************************
	> File Name: 04_using.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年08月05日 星期三 10时47分35秒
 ************************************************************************/

#include<iostream>
using namespace std;



namespace KingGlory{
    int sun =10;
}


void test01(){
    int sun = 10;
    //using生命 注意避免二义性问题
    //using声明后， 下面这行代码会是 KingGlory下的sun ， 但是 编译器又有就近原则， 产生二义性。
    //using KingGlory::sun;

    cout << sun << endl;
}

//using 编译指令

namespace LOL{
    int sun = 30;

}
void test02(){
   // int sun = 20;

    //using编译指令
    using namespace KingGlory; //打开王者荣耀房间
    using namespace LOL; //打开LOL房间
  //  cout << sun << sendl; //产生二义性
    cout << LOL::sun;
}

int main(){
    test01();
    test02();
    return 0;
}
