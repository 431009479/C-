/*************************************************************************
	> File Name: 33.turing.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年08月13日 星期四 14时35分12秒
 ************************************************************************/

#include<iostream>
using namespace std;

//IsEXen
template<int n>
struct IsEXen{
    static constexpr int r = !(n % 2);
};

//Add
template<int n, int m>
struct Add{
    static constexpr int r = n + m;
};

//Sum
template<int n>
struct Sum{
    static constexpr int r = n + Sum<n - 1>::r; 
};

template<>
struct Sum<0>{
    static constexpr int r = 0;
};

//Factorial
template<int n>
struct Factorial{
    static constexpr int r = n * Factorial<n - 1>::r;
};

template<>
struct Factorial<1>{
    static constexpr int r = 1;
};

template<int i, int n>
struct getNextN{
    static constexpr int r = (i * i > n ? 0 : n);
};

template<int i, int n>
struct getNextI{
    static constexpr int r = (n % i == 0 ? 0 : i + 1);
};

template<int i, int n>
struct Test{
    static constexpr int r = Test<getNextI<i, n>::r, getNextN<i, n>::r>::r;
};
template<int n>
struct Test<0, n>{
    static constexpr int r = 0;
};

template<int i>
struct Test<i, 0>{
    static constexpr int r = 1;
};

template<int i>
struct Test<i, 2>{
    static constexpr int r = 1;
};

template<int n>
struct IsPrime{
    static constexpr int r = Test<2, n>::r;
};
template<int n>
struct SumPrime{
    static constexpr int r = n * IsPrime<n>::r + SumPrime<n - 1>::r;
};
template<>
struct SumPrime<2>{
    static constexpr int r = 2;
};

/*template<int i, int x>
struct getNextK2 {
    constexpr static int r = (i > x ? 0 : 1);
};

template<int x>
struct print_prime {
    template<int i, int k>
    struct __output {
        static void run() {
            if (IsPrime<i>::r) {
                cout << i << endl;
            }
            print_prime<x>::__output<i + 1, getNextK2<i + 1, x>::r >::run();
        }
    };
    template<int i>
    struct __output<i, 0> {
        static void run() {
            return ;
        }
    };
    static void output() {
        print_prime<x>::__output<2, 1>::run();
        return ;
    }
};
*/
template<int n, int i>
struct Print{
    static void run(){
        if(IsPrime<i>::r){
            cout << i << endl;
        }
        Print<n, i + 1>::run();
    }
};

template<>
struct Print<1, 2>{
    static void run(){
        return ;
    }
};

template<int n>
struct Print<n, n>{
    static void run(){
        if(IsPrime<n>::r){
            cout << n << endl;
        }
        return ;
    }
};

template<int n>
struct print_prime{
    static void print(){
        if(n < 2) return ;
        Print<n, 2>::run();
    }
};
int main(){
  /*  cout <<IsEXen<123>::r << endl;
    cout <<IsEXen<124>::r << endl;
    cout << Add<97, 98>::r << endl;
    cout << Sum<10>::r << endl;
    cout << Sum<100>::r <<endl;
    cout << Factorial<5>::r << endl;
    cout << IsPrime<9973>::r<< endl;
    cout << IsPrime<87>::r << endl;
    cout << IsPrime<1537>::r << endl;
    cout << IsPrime<65>::r << endl;
    cout << SumPrime<10>::r << endl;*/
    print_prime<1>::print();
    return 0;
}
