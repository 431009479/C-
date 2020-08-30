/*************************************************************************
	> File Name: project.h
	> Author: 
	> Mail: 
	> Created Time: 2020年08月30日 星期日 13时50分58秒
 ************************************************************************/

#ifndef _PROJECT_H
#define _PROJECT_H
#include<iostream>
#include<AST.h>
#include<stdio.h>
#include<string>
#include<map>
using namespace std;


class Scope;
class Only;
class Object;
class Plant;
class INT;
class PINT;
class Begin;
class PBegin;
class Print;
class PBegin;


class Scope{
public:
    Scope(Scope *next): next(next){}
    int set(string, int);
    int get(string);
    int add(string);
    Scope *next;

private:
    map<string, int> memory;
};

class Only{
public:
    static Only *get(){
        if(Only::single) return Only::single;
        Only::single = new Only();
        return Only::single;
    }
    static void del(){
        if(Only::single == nullptr) return;
        Only::single->~Only();
        return ;
    }
    int judge(haihei::ASTNode);
private:
    static Only *single;
    Only(){}
    ~Only(){}
    Plant *p;
};
Only *Only::single = nullptr;

Only::Only(){
    this->p = new Begin::PBegin();
    this->p->next = new next INT::INT();
    this->p->next->next = new Print::PPrint();
}



class Object{
    virtual int run (haihei::AST) = 0;
    virtual ~Object(){}
};

class Plant{
public:
    vritual int judge(haihei::ASTNode) = 0;
    vritual Object conversion() = 0;
    Plant *next;
    vritual ~Plant(){}
};

class Begin : public Object{
public:
    class PBegin : public Plant{
        int judge(haihei::ASTNode);
        Object conversion();
    }
    int run(haihei::ASTNode);
};

class INT : public Object{
public:
    class PINT : public Plant{
        int judge(haihei::ASTNode);
        Object conversion();
    }
    int run(haihei::ASTNode);
};

class Print : public Object{
public:
    class PPrint : public Plant{
        int judge(haihei::ASTNode);
        Object conversion();
    }
    int run(haihei::ASTNode);
};
#endif
