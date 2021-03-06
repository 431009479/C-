/*************************************************************************
	> File Name: AST.h
	> Author: 
	> Mail: 
	> Created Time: 2020年08月27日 星期四 23时41分16秒
 ************************************************************************/

#ifndef _AST_H
#define _AST_H

#include <hythonLexer.h>
#include <hythonParser.h>
#include <string>

namespace haizei {

class ASTNode {
public :
    ASTNode(const char *file_name);
    ASTNode(pANTLR3_BASE_TREE);
    int size();
    std::string text();
    ASTNode operator[](int);
    bool hasToken();
    int type();
    void destroy();
    ~ASTNode();
    pANTLR3_COMMON_TOKEN tok;
private:
    pANTLR3_INPUT_STREAM input;
    phythonLexer lex;
    pANTLR3_COMMON_TOKEN_STREAM tokens;
    phythonParser parser;
    pANTLR3_BASE_TREE tree;

    void init_tree(const char *file_name);
};

} // end of namespace haizei
#endif
