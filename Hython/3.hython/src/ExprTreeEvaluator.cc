#include <cassert>
#include <ExprTreeEvaluator.h>
#include <iostream>
#include <string>
#include <AST.h>

ExprTreeEvaluator::ExprTreeEvaluator() : next(nullptr) {}
ExprTreeEvaluator::ExprTreeEvaluator(ExprTreeEvaluator *next) : next(next) {}

void ExprTreeEvaluator::def_param(std::string name, int val) {
    if (memory.find(name) != memory.end()) {
        #ifdef DEBUG
        for (auto x : memory) {
            cout << "debug log(memory) : " << x.first << " " << x.second << endl;
        }
        #endif
        throw std::runtime_error("param redefined : " + name);
    }
    memory[name] = val;
    return ;
}

void ExprTreeEvaluator::set_param(std::string name, int val) {
    if (memory.find(name) != memory.end()) {
        memory[name] = val;
        return;
    }
    if(this->next) return this->next->set_param(name, val);
    std::cout << "undefined "<< name << std::endl;
    return;
}


int ExprTreeEvaluator::get_param(std::string name) {
    if (memory.find(name) == memory.end()) {
        if (this->next) return this->next->get_param(name);
        throw std::runtime_error("unknown param : " + name);
    }
    return memory[name];
}


int ExprTreeEvaluator::run(haizei::ASTNode tree) {
    if(tree.hasToken()) {
        switch(tree.type()) {
        case INT: {
            std::string s = tree.text();
            if(s[0] == '~') {
                return -atoi(s.c_str() + 1);
            }
            else {
                return atoi(s.c_str());
            }
        }
        case ID: {
            return get_param(tree.text());
        }
        case PLUS:
            return run(tree[0]) + run(tree[1]);
        case MINUS:
            return run(tree[0]) - run(tree[1]);
        case TIMES:
            return run(tree[0]) * run(tree[1]);
        case DIV:
            return run(tree[0]) / run(tree[1]);
        case MOD:
            return run(tree[0]) % run(tree[1]);
          case GE:
            return run(tree[0]) >= run(tree[1]);
        case LE:
            return run(tree[0]) <= run(tree[1]);
        case NE:
            return run(tree[0]) != run(tree[1]);
        case EQ:
            return run(tree[0]) == run(tree[1]);
        case OR:
            return run(tree[0]) || run(tree[1]);
        case AND:
            return run(tree[0]) && run(tree[1]);
        case GT:
            return run(tree[0]) > run(tree[1]);
        case LITTLE:
            return run(tree[0]) < run(tree[1]);
        case NO:
            return 1;
        case BLOCK: {
            ExprTreeEvaluator new_this(this);
            for (int i = 0; i < tree.size(); i++) {
                int val = new_this.run(tree[i]);
          //      cout << "Block Value : " << val << endl;
            }
            return 0;
        } break;
        case DEF: {
            int init_val = 0;
            for (int i = 0; i < tree.size(); i++) {
                std::string var(tree[i].text());
                init_val = 0;
                if (tree[i].size() == 1) {
                    init_val = run(tree[i][0]);
                }
             //   cout << "def param val : " << var << " = " << init_val << endl;
                this->def_param(var, init_val);
            }
            return init_val;
        } break;
         case PRINT:{
             for(int i = 0;  i <tree.size(); i++){
                 if(i != 0) std::cout << " ";
                 std::cout << run(tree[0]);
            }
             std::cout << std::endl;
            return 0;
        }break;
         case IF:{
            if(run(tree[0])){
                run(tree[1]);
            }else{
                if(tree.size() == 3)
                    run(tree[2]);
            }
            return 0;
        }break;
        case FOR:{
            int val = 0;
            for(run(tree[0]); run(tree[1]); run(tree[2])){
                val = run(tree[3]);
            }
            return val;
        }break;
        case WHILE : {
            int val;
            while(run(tree[0])){
                val = run(tree[1]);
            }
            return val;
        }break;
        case DOWHILE:{
            int val;
            do{
               val = run(tree[1]);
            }while(run(tree[0]));
            return val;
        }
        case ASSIGN: {
            std:: string var(tree[0].text());
            get_param(var);
            int val = run(tree[1]);
            set_param(var, val);
            return val;
        }
        default:
            std::cout << "Unhandled token: #" << tree.type() << '\n';
            return -1;
        }
    } else {
        int r = 0;
        for(int i = 0; i < tree.size(); i++) {
            r = run(tree[i]);
            std::cout << "Evaluator result: " << r << std::endl;
        }
        return r;
    }
    return 0;
}

