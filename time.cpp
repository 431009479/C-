/*************************************************************************
	> File Name: time.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年08月12日 星期三 12时09分07秒
 ************************************************************************/

#include<iostream>
using namespace std;


class Date{
    public:
    void setYear(int y);
    void setMonth(int m);
    void setDoy(int d);
    void setDate(int y, int m, int d);//修改年月日

    void printDate(); //打印日期

    int isLeap(); //判断闰年
    int namberOfDay(); //求第几天

private: //成员属性一般是私有的
    int year;
    int month;
    int day;
};


void Date::setYear(int y){
    year = y;
}
void Date::setMonth(int m){
    month = m;
}
void Date::setDoy(int d){
    day = d;
}
void Date::setDate(int y, int m, int d){
    year = y;
    month = m;
    day = d;
}

void Date::printDate(){
    cout <<year << "年" << month <<"月" << day << "日" << endl;
}

int Date::isLeap(){
    int flag = 0;
    if(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)){
        flag = 1;
    }
    return flag;
}


int Date::namberOfDay(){
    int a[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int number = 0;
    if(isLeap()){
        a[2] = 29;
    }
    for(int i = 1; i < month; i++){
        number += a[i];
    }
    number += day;
    return number;
}

int main(){
    Date  date;
    int y, m, d;
    cin >> y >> m >> d;
    date.setDate(y, m, d);
    cout << date.namberOfDay() << endl;
    return 0;
}
