/*************************************************************************
	> File Name: project.c
	> Author: 
	> Mail: 
	> Created Time: 2020年08月30日 星期日 14时20分41秒
 ************************************************************************/

#include <stdio.h>
#include "project.h"
#include <AST.h>

int Scope::get(string name) {
    if (this->memory.find(name) != this->memory.end()) 
        return this->memory[name];
    if (this->next == nullptr) {
        throw runtime_error(name + " is not a varable!");
        return -1;
    }
    return this->next->getVal(name);
}

int Scope::set(string name, int val) {
    if (this->memory.find(name) != this->memory.end()) 
        return this->memory[name] = val;
    if (this->next == nullptr) {
        throw runtime_error(name + " is not a varable!");
        return -1;
    }
    return this->next->set(name, val);
}

int Scope::add(string name) {
    if (this->memory.find(name) == this->memory.end()) {
        this->memory[name] = 0;
        return 1;
    }
    cout << name << "Scope::add" << endl;   
    return 0;
}



int Only::judge(haizei::ASTNode tree){
    Plant *p = this->p;
    while(p){
        if(p->judge(tree)){
            Object *b = p->conversion();
            b->run();
            return 0;
        }
        p = p->next;
    }
    cout << "Unhandled token: #" << tree.type() << '\n';
    return 0;
}

int Begin::PBegin::judge(haizei::AST tree){
    if(!tree.tok) return 0;
    switch(tree.type()){
        case BLOCK:
        return 1; 
    }
    return 0;
}

Plant *Begin::PBegin::conversion(){
    return new Begin();
}

int Begin::run(){
    this->

}



int INT::PINT::judge(haizei::AST tree){
    if(!tree.tok) return 0;
    switch(tree.type()){
        case DEF:
        case INT:
        case PLUS:
        case MINUS:
        case TIMES:
        case AND:
        case ASSIGN:
        case EQ:
        case GE:
        case GT:
        case LE:
        case LITTLE: 
        case NE:
        case OR:
        case ID:
        case DIV:
        case MOD:
        case NO:
        case WHILE:
        case DOWHILE:
        case FOR:
        return 1; 
    }
    return 0;
}

Plant *INT::PINT::conversion(){
    return new INT();
}




int INT::run(){
    this->

}




int Print::PPrint::judge(haizei::ASTNode tree){
    if(!tree.tok) return 0;
    switch(tree.type()){
        case PRTIN:
        return 1; 
    }
    return 0;
}

Plant *Print::Print::conversion(){
    return new Begin();
}

int Begin::run(haizei::ASTNode tree){
    switch(tree.type()){
        case PRTIN:
            for (int i = 0; i < tree.size(); i++) {
                if (i) printf(" ");
                int val = MasterChain::get()->valid(tree[i]);
            }
            printf("\n");
            return 0;
    }
    cout << "Unhandled token: #" << tree.type() << '\n';
   return 0; 
}

