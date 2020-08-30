#include <stdio.h>
#include <AST.h>
#include "program_master.h"

MasterChain *MasterChain::single = nullptr;

MasterChain::MasterChain() {
    this->p = new ProgramMaster::IProgramFactory();
    this->p->next = new IFMaster::IIFFactory();
    this->p->next->next = new ExprMaster::IExprFactory();
    this->p->next->next->next = new PrintMaster::IPrintFactory();

}

MasterChain::~MasterChain() {
    IFactory *next = this->p;
    while (next) {
        this->p = next->next;
        delete next;
        next = this->p;
    }
}

int MasterChain::valid(haizei::ASTNode tree, Parameters *param) {
    IFactory *f = this->p;
    while (f) {
        if (f->valid(tree)) {
            IMaster *m = f->creator(param);
            int ret = m->run(tree);
            delete m;
            return ret;
        }
        f = f->next;
    }
    cout << "Unhandled token: #" << tree.type() << '\n';
    throw runtime_error("There is no Master could take over The Tree!");
    return -1;
}

int Parameters::getVal(string name) {
    if (this->memory.find(name) != this->memory.end()) 
        return this->memory[name];
    if (this->next == nullptr) {
        throw runtime_error(name + " is not a varable!");
        return -1;
    }
    return this->next->getVal(name);
}

int Parameters::setVal(string name, int val) {
    if (this->memory.find(name) != this->memory.end()) 
        return this->memory[name] = val;
    if (this->next == nullptr) {
        throw runtime_error(name + " is not a varable!");
        return -1;
    }
    return this->next->setVal(name, val);
}

int Parameters::addVar(string name) {
    if (this->memory.find(name) == this->memory.end()) {
        this->memory[name] = 0;
        return 1;
    }
    throw runtime_error(name + " re-declared!");   
    return 0;
}

int ProgramMaster::IProgramFactory::valid(haizei::ASTNode tree) {
    if (!tree.tok) return false;
    switch (tree.type()) {
        case BLOCK:
            return true;
    }
    return false;
}

IMaster *ProgramMaster::IProgramFactory::creator(Parameters *param) {
    return new ProgramMaster(param);
}

int ProgramMaster::run(haizei::ASTNode tree) {
        switch(tree.type()) {
            case BLOCK: {
                // 增加作用域
                this->param = new Parameters(this->param);
                for (int i = 0; i < tree.size(); i++) {
                    MasterChain::get()->valid(tree[i], this->param);
                }
                break;
            }
            default: {
                cout << "Unhandled token: #" << tree.type() << '\n';
                break;
            }
        }
    return 0;
}

int IFMaster::IIFFactory::valid(haizei::ASTNode tree) {
    if (!tree.tok) return false;
    switch (tree.type()) {
        case IF:
        case WHILE:
        case DOWHILE:
        case FOR:
            return true;
    }
    return false;
}

IMaster *IFMaster::IIFFactory::creator(Parameters *param) {
    return new IFMaster(param);
}

int IFMaster::run(haizei::ASTNode tree) {
    switch (tree.type()) {
        case IF: {
            int ret = MasterChain::get()->valid(tree[0], this->param);
            if (ret) {
                return MasterChain::get()->valid(tree[1], this->param); 
            } else {
                if (tree.size() == 3)
                return MasterChain::get()->valid(tree[2], this->param);
            }
        }
        case WHILE: {
            while (MasterChain::get()->valid(tree[0], this->param)) {
                    MasterChain::get()->valid(tree[1], this->param);
            }
            break;
        }
        case DOWHILE: {
            do {
                MasterChain::get()->valid(tree[1], this->param);
            } while (MasterChain::get()->valid(tree[0], this->param));
            break;
        }
        case FOR: {
            MasterChain::get()->valid(tree[0], this->param);
            while (MasterChain::get()->valid(tree[1], this->param)) {
                MasterChain::get()->valid(tree[3], this->param);
                MasterChain::get()->valid(tree[2], this->param);
            }
            break;
        }
        default :
            cout << "Unhandled token: #" << tree.type() << '\n';
            break;
    }
    return 0;
}

int ExprMaster::IExprFactory::valid(haizei::ASTNode tree) {
    if (!tree.tok) return false;
    switch (tree.type()) {
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
            return true;
    }
    return false;
}

IMaster *ExprMaster::IExprFactory::creator(Parameters *param) {
    return new ExprMaster(param);
}

int ExprMaster::run(haizei::ASTNode tree) {
    switch (tree.type()) {
        case DEF: {
            int val = 0;
            for (int i = 0; i < tree.size(); i++) {
                string var(tree[i].text());
                this->param->addVar(var);
                if (tree[i].size()) {
                    val = MasterChain::get()->valid(tree[i][0], this->param);
                    this->param->setVal(var, val);
                }
            }
            return val;
        }
        case INT: {
            std::string s = tree.text();
            if(s[0] == '~') {
                return -atoi(s.c_str() + 1);
            }
            else {
                return atoi(s.c_str());
            }
        }
        case PLUS: {
            int a = MasterChain::get()->valid(tree[0], this->param);
            int b = MasterChain::get()->valid(tree[1], this->param);
            return a + b;
        }
        case MINUS: {
            int a = MasterChain::get()->valid(tree[0], this->param);
            int b = MasterChain::get()->valid(tree[1], this->param);
            return a - b;
        }
        case TIMES: {
            int a = MasterChain::get()->valid(tree[0], this->param);
            int b = MasterChain::get()->valid(tree[1], this->param);
            return a * b;
        }
        case DIV: {
            int a = MasterChain::get()->valid(tree[0], this->param);
            int b = MasterChain::get()->valid(tree[1], this->param);
            return a / b;
        }
        case MOD: {
            int a = MasterChain::get()->valid(tree[0], this->param);
            int b = MasterChain::get()->valid(tree[1], this->param);
            return a % b;
        }
        case AND: {
            int a = MasterChain::get()->valid(tree[0], this->param);
            int b = MasterChain::get()->valid(tree[1], this->param);
            return (a && b);
        }
        case ASSIGN: {
            string var(tree[0].text());
            int val = MasterChain::get()->valid(tree[1], this->param);
            this->param->setVal(var, val);
            return val;
        }
        case EQ: {
            int a = MasterChain::get()->valid(tree[0], this->param);
            int b = MasterChain::get()->valid(tree[1], this->param);
            return (a == b);
        }
        case GE: {
            int a = MasterChain::get()->valid(tree[0], this->param);
            int b = MasterChain::get()->valid(tree[1], this->param);
            return (a >= b);
        }
        case GT: {
            int a = MasterChain::get()->valid(tree[0], this->param);
            int b = MasterChain::get()->valid(tree[1], this->param);
            return (a > b);
        }
        case LE: {
            int a = MasterChain::get()->valid(tree[0], this->param);
            int b = MasterChain::get()->valid(tree[1], this->param);
            return (a <= b);
        }
        case LITTLE: {
            int a = MasterChain::get()->valid(tree[0], this->param);
            int b = MasterChain::get()->valid(tree[1], this->param);
            return (a < b);
        }
        case NE: {
            int a = MasterChain::get()->valid(tree[0], this->param);
            int b = MasterChain::get()->valid(tree[1], this->param);
            return (a != b);
        }
        case OR: {
            int a = MasterChain::get()->valid(tree[0], this->param);
            int b = MasterChain::get()->valid(tree[1], this->param);
            return (a || b);
        }
        case ID: {
            string var(tree.text());
            return this->param->getVal(var);
        }
        case NO: {
            return 1;
        }
        default :
            cout << "Unhandled token: #" << tree.type() << '\n';
            break;
    }
    return 0;
}

int PrintMaster::IPrintFactory::valid(haizei::ASTNode tree) {
    if (!tree.tok) return false;
    switch (tree.type()) {
        case PRINT:
            return true;
    }
    return false;
}

IMaster *PrintMaster::IPrintFactory::creator(Parameters *param) {
    return new PrintMaster(param);
}

int PrintMaster::run(haizei::ASTNode tree) {
    switch (tree.type()) {
        case PRINT: {
            int ret = 0;
            for (int i = 0; i < tree.size(); i++) {
                if (i) printf(" ");
                int val = MasterChain::get()->valid(tree[i], this->param);
                ret += printf("%d", val);
            }
            ret += printf("\n");
            return ret;
        }
        default:
            cout << "Unhandled token: #" << tree.type() << '\n';
            break;
    }
    return 0;
}

