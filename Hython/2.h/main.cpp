/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年08月24日 星期一 11时15分28秒
 ************************************************************************/


#include <hythonLexer.h>
#include <hythonParser.h>
#include <cassert>
#include <map>
#include <string>
#include <iostream>
#include "program_master.h"
#include <AST.h>

int main(int argc, char* argv[]) {
    assert(argc > 1);
    haizei::ASTNode tree(argv[1]);

    ProgramMaster eval;
    int rr = eval.run(tree);
//    cout << "Evaluator result: " << rr << '\n';
    tree.destroy();
    return 0;
}


