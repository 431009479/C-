/*************************************************************************
	> File Name: 41.factory.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年08月23日 星期日 14时28分53秒
 ************************************************************************/

#include<iostream>
using namespace std;
class ICar{
public:
    class IFactory{
    public :
        virtual ICar *created() = 0;
    };
    virtual void run() = 0;
protected:
    ICar(){};
    ~ICar(){};
};

class BanzCar : public ICar{
public:
    class Facory : public ICar::IFactory{
    public:
        virtual ICar *created(){
            return new BanzCar();
        }
    };
    void run(){
        cout <<"Banz run" << endl;
    }
private:
    BanzCar(){};
};

class BmwCar : public ICar{
public:
    class Facory : public ICar::IFactory{
    public :
        virtual ICar *created(){
            return new BmwCar();
        }
    };
    void run(){
        cout << "Bmw run" << endl;
    }
private:
    BmwCar(){};
};

class AudiCar : public ICar{
public :
    class Facory : public ICar::IFactory{
    public :
        virtual ICar *created(){
            return new AudiCar();
        }
    };
    void run(){
        cout << "Audi run" << endl;
    }
private:
    AudiCar(){}
};


    ICar::IFactory *fac[3] = {new BanzCar::Facory(), new BmwCar::Facory(), new AudiCar::Facory};

int main(){
    srand(time(0));
    ICar *cars[10];
    for(int i = 0; i < 10; i++){
        cars[i] = fac[rand() % 3] ->created();
    }
    for(int i = 0; i  < 10; i++){
        cars[i]->run();
    }
    return 0;
}
