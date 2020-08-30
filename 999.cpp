/*************************************************************************
	> File Name: 999.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年08月03日 星期一 18时34分55秒
 ************************************************************************/

#include<iostream>
using namespace std;
class A{
public:
    A(int x): x(x){}
    void say(int x){
        cout << " class A :" << endl;
        cout << this->x;
    }
private:
    int x;
};



int main(){
    
    A a(5);
    A b(10);
    a.say(5);
    a.say(&b, 5);

    return 0;
}
