/*************************************************************************
	> File Name: 42.handle.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年08月23日 星期日 15时46分50秒
 ************************************************************************/

#include<iostream>
using namespace std;



class ICar{
public:
    class IFactory{
    public:
        virtual ICar *created() = 0;
    };

    class IHandler{
    public:
        IHandler() :next(nullptr){}
        virtual bool is_valid(int x) = 0;
        virtual ICar *do_it() = 0;
        IHandler *next;
    };
    virtual void run() = 0;
protected:
    ICar(){}
    ~ICar(){}
};

class BenzCar : public ICar {
    BenzCar() {}
public :
    class Facory : public ICar::IFactory, public ICar::IHandler {
    public :
         ICar *created() {
            return new BenzCar();
        }
         bool is_valid(int x) {
            return x == 0;
        }
         ICar *do_it() {
            return this->created();
        }
    };
    virtual void run() {
        cout << "Benz run" << endl;
    }
};
class BmwCar:public ICar{
    BmwCar(){}
public:    
    class Facory :public IFactory, public IHandler{
        ICar *created(){
            return new BmwCar;
        }
        bool is_valid(int x){
            return x == 1;
        }
        ICar *do_it(){
            return this->created();
        }
    };
    void run(){
        cout << "BmwCarr run" << endl;
    }    
};

class AudiCar :public ICar{
public:    
    class Facory :public IFactory, public IHandler{
        ICar *created(){
            return new AudiCar;
        }
        bool is_valid(int x){
            return x == 2;
        }
        ICar *do_it(){
            return this->created();
        }
    };
    void run(){
        cout << "AudiCar run" << endl;
    }
private:
    AudiCar() {}

};

class ChainMaster {
public :
    static ICar::IHandler *getInstance() {
        if (head == nullptr) {
            buildChain();
        }
        return head;
    }
private :
    static ICar::IHandler *head;
    static void buildChain() {
        head = new BenzCar::Facory();
        head->next = new BmwCar::Facory();
        head->next->next = new AudiCar::Facory();
        return ;
    }
};

ICar::IHandler *ChainMaster::head = nullptr;

int main(){
    srand(time(0));
    ICar *cars[10];
    for(int i = 0; i < 10; i++){
        int req = rand() % 3;
        for(auto p =ChainMaster::getInstance(); p; p = p->next){
            if(p->is_valid(req)){
                cars[i] = p->do_it();
                cars[i]->run();
            }
        }
    }
    
   /* for(int i = 0; i < 10; i++){
        cars[i]->run();
    }*/
    return 0;
}
