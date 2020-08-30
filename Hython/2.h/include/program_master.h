#ifndef _PROGRAM_MASTER_H
#define _PROGRAM_MASTER_H

#include <cassert>
#include <map>
#include <string>
#include <iostream>
#include <stdexcept>
#include <AST.h>

using std::map;
using std::string;
using std::cout;
using std::runtime_error;

class MasterChain;
class Parameters;

class IMaster;
class ProgramMaster;
class IFMaster;
class ExprMaster;
class IProgramFactory;
class IIFFactory;
class IExprFactory;

class IFactory { //工厂类
public:
    virtual int valid(haizei::ASTNode) = 0;
    virtual IMaster *creator(Parameters *) = 0;
    IFactory *next;
    virtual ~IFactory() {}
};

class MasterChain {
public :
    static MasterChain *get() {
        if (MasterChain::single) return MasterChain::single;
        MasterChain::single = new MasterChain();
        return MasterChain::single;
    }
    static void destroy() {
        if (MasterChain::single == nullptr) return ;
        MasterChain::get()->~MasterChain();
        MasterChain::single = nullptr;
    }
    int valid(haizei::ASTNode, Parameters *);
private:
    static MasterChain *single;
    MasterChain();
    ~MasterChain();
    IFactory *p;
};

class Parameters {
public :
    Parameters(Parameters *next) : next(next) {}
    int getVal(string);
    int setVal(string, int);
    int addVar(string);
    Parameters *next;
private:
    map<string, int> memory;
};

class IMaster {
public:
    IMaster(Parameters *param) : param(param) {}
    virtual ~IMaster() {}
    virtual int run(haizei::ASTNode) = 0;
protected:
    Parameters *param;
};

class ProgramMaster : public IMaster {
public:
    class IProgramFactory : public IFactory {
    public :
        int valid(haizei::ASTNode);
        IMaster *creator(Parameters *);
    };
    ProgramMaster() : IMaster(nullptr) {}
    ProgramMaster(Parameters *param) : IMaster(param) {}
    int run(haizei::ASTNode);
};

class IFMaster : public IMaster {
public:
    class IIFFactory : public IFactory {
    public :
        int valid(haizei::ASTNode);
        IMaster *creator(Parameters *);
    };  
    IFMaster() : IMaster(nullptr) {}
    IFMaster(Parameters *param) : IMaster(param) {}
    int run(haizei::ASTNode);
};

class ExprMaster : public IMaster {
public:
    class IExprFactory : public IFactory {
    public :
        int valid(haizei::ASTNode);
        IMaster *creator(Parameters *);
    };
    ExprMaster() : IMaster(nullptr) {}
    ExprMaster(Parameters *param) : IMaster(param) {}
    int run(haizei::ASTNode);
};

class PrintMaster : public IMaster {
public:
    class IPrintFactory : public IFactory {
    public :
        int valid(haizei::ASTNode);
        IMaster *creator(Parameters *);
    };
    PrintMaster() : IMaster(nullptr) {}
    PrintMaster(Parameters *param) : IMaster(param) {}
    int run(haizei::ASTNode);
};

#endif
