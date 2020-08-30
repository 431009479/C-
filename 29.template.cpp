/*************************************************************************
	> File Name: 29.template.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年08月06日 星期四 11时46分26秒
 ************************************************************************/

#include<iostream>
using namespace std;

class A{
public:
    A(int x) :x(x){};
    int x;
};

class B{
public:
    B(int x) :x(x){};
    int x;
};

int operator+(const A &a, const B &b){
        return a.x + b.x;
}
int operator>(const A &a, const B &b){
    return a.x > b.x ? a.x : b.x;
}

/*decltype(T() + U()) add(T a, U b){ //decltype推导返回值类型
    return a + b;
}*/
namespace haizei{
template<typename T, typename U>
auto add(T a, U b)->decltype(a + b){ 
    return a + b;
}

template <typename T, typename U>
    auto Max(T a, U b)->decltype(a + b){
        return a > b ? a : b;
}

template <typename T, typename U>
    auto Min(T a, U b)->decltype(a + b){
        return a > b ? b : a;
}

template <>
int add (int a, int b){
    cout << "add int : " << a << " " << b << endl;
    return a + b;
}

template<typename T, typename U>
auto add(T *a, U *b)->decltype(*a + *b){ 
    return add(*a, *b);
}

/*template<typename T>
class PrintAny{
public:
    void operator()(const T &a){
        cout << a << endl;
    }
};*/
class PrintAny{
public:
    template<typename T>
    void operator()(const T &a){
        cout << a << endl;
    }
};
template<typename T>
class FoolPrintAny{
public:
    void operator()(const T &a){
        cout << a << endl;
    }
};

template<>
class FoolPrintAny<int>{
public:
    void operator()(const int &a){
        cout << "naughty : " << 2 * a << endl;
    }
};

template<typename T>
void printAny(const T &a){
    cout << a <<'\n';
    return;
}
template<typename T, typename ...ARGS>
void printAny(const T &a, ARGS...args){
    cout << a << " ";
    printAny(args...);
    return ;

}

template<int n,typename T, typename ...ARGS>//int n 是编译期常量，
struct ARG{
    typedef typename ARG<n - 1, ARGS...>::getT getT;
};

template<typename T, typename ...ARGS>
struct ARG<0, T, ARGS...>{
    typedef T getT;
};


template<typename T>
struct ARG<0, T>{
    typedef T getT;
};

template<typename T, typename ...ARGS> class Test;
template<typename T, typename ...ARGS>
class Test<T(ARGS...)> {
public:
    T operator()(ARGS... args) {
        return add<T>(args...);
    }
private:
    template<typename T1,typename U, typename ...US>
    T1 add(U a, US ...args) {
        return a + add<T1>(args...);
    }
    template<typename T1, typename U>
    T1 add(U a) {
        return a;
    }
};
template<typename T, typename U>
T Test_param_func(U a){
    return 2 * a;
}

void func2(int (*func)(double)){ //模板函数作为参数,传递时的间接类型推导
    cout << func(2.3) << endl;
}


template<typename T> struct remove_reference{    typedef T type; };
template<typename T> struct remove_reference<T &>{    typedef T type; };
template<typename T> struct remove_reference<T &&>{    typedef T type;};

template<typename T> struct add_const{typedef const T  type; };
template<typename T> struct add_const<const T>{typedef const T  type; };

template<typename T> struct add_lvalue_reference{typedef T &type; };
template<typename T> struct add_lvalue_reference<T &>{typedef T &type; };
template<typename T> struct add_lvalue_reference<T &&>{typedef T &type; };

template<typename T> struct add_rvalue_reference{typedef T&& type;};
template<typename T> struct add_rvalue_reference<T &>{typedef T&& type;};
template<typename T> struct add_rvalue_reference<T &&>{typedef T&& type;};

template<typename T> struct remove_pointer{typedef T type;};
template<typename T> struct remove_pointer<T *>{typedef typename remove_pointer<T>::type type;};


template<typename T>
typename add_rvalue_reference<T>::type move(T &&a){ //实现move
    return typename add_rvalue_reference<T>::type(a);
}

int f(int &x){
    cout << "f function : left value" << endl;
    return x;
}
int f(int &&x){
    x = 9973;
    cout << "f function : reft value" << endl;
    return x;
}

template<typename T>
typename add_const<T>::type const_a(T a){
    typename add_const<T>::type b = a;
    return b;
}

template<typename T>
typename remove_pointer<T>::type a_func(T a){
    typename remove_pointer<T>::type b = *a;
    return b;
}

template<typename T>
typename add_lvalue_reference<T>::type l_func(T a){
    typename add_lvalue_reference<T>::type b = a;
    return b;
}

template<typename T>
typename add_rvalue_reference<T>::type r_func(T a){
    typename add_rvalue_reference<T>::type b = a;
    return b;
}
template<typename T>
typename remove_reference<T>::type add2(T &&a, T &&b){ //在模板中两个&&是引用。左值时 T 为 int& 右值时 T为 int
        typename remove_reference<T>::type c = a + b;
        return  c;
}

} 

int main(){
    haizei::func2(haizei::Test_param_func);
    int arr1 = 2, arr2 = 3;
    cout << haizei::add2(arr1, arr2) << endl;
    cout << haizei::add2(27, 73) << endl;
    cout << haizei::const_a(6) << endl;
    cout << haizei::a_func(&arr2) << endl;
  //  cout << haizei::r_func(123) << endl;
    cout << haizei::l_func(arr2) << endl;

    A a(1000);
    B b(655);
    cout << a + b << endl;
    cout << haizei::add(2, 3) << endl;
    cout << haizei::add(2.3, 4.8) << endl;
//    cout << add(2.3, 5) << endl; T::2.3是double ； T;:5 是int
    cout << haizei::add<double>(2.3, 5) << endl;//显示实例化 强转double
    cout << haizei::add(5, 2.3) << endl;
    cout << haizei::add(a, b) << endl;
    cout << haizei::Max(10, 100) << endl;
   /* haizei::PrintAny<int> print1;
    haizei::PrintAny<string> print2;
    print1(123);
    print2("hleeo");*/
    haizei::PrintAny print;
    print(123);
    print(3.5);
    print("haizei");
    print(&a);
    haizei::FoolPrintAny<string> f;
    f("hello world");
    haizei::FoolPrintAny<int> f2;
    f2(123);
    int n = 45, m = 67;
    int *p = &n, *q = &m;
    cout << haizei::add(n, m) << endl;
    cout << haizei::add(p, q) << endl;
    haizei::printAny(123, 234, "kill");
    //haizei::Test<int(int, int, int)> f3;
    //cout << f3(4, 8) << endl;
    haizei::Test<int(int, int, int, int)> f4;
    cout << f4(1, 2, 4.8, 1.2) << endl;


    haizei::f(n);
    haizei::f(haizei::move(n));
    cout << n << endl;
    return 0;
}
