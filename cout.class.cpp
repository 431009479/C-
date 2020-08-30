/*************************************************************************
	> File Name: cout.class.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年07月29日 星期三 17时52分26秒
 ************************************************************************/

#include <iostream>
#include <string>

namespace haizei {
    class ostream {
    public :
        ostream &operator<<(int x) {
            printf("%d", x);
            return *this;
        }
        ostream &operator<<(const std::string &str) {
            printf("%s", str.c_str());
            return *this;
        }
        ostream &operator<<(const char &ch) {
            printf("%c", ch);
            return *this;
        }
        ostream &operator<<(const double &a) {
            printf("%g", a);
            return *this;
        }
    };
    char endl = '\n';
    ostream cout;
}

int main() {
    haizei::cout << "hello world" << haizei::endl;
    haizei::cout << 123 << haizei::endl;
    haizei::cout << 123.567 << haizei::endl;
    haizei::cout << 123.56 << haizei::endl;
    haizei::cout << 123. << 123. <<  haizei::endl;
    std::cout << 123. << 123. <<  std::endl;
  //  haizei::cout << 123.78787878 << haizei::endl;
  //  haizei::cout << 3.78787878 << haizei::endl;
   /* double a = 3787878787878780.;
    for (int i = 0; i < 20; i++) {
        a /= 10;
        haizei::cout << i << " " << a << haizei::endl;
    }*/
    printf("%lf\n", 123.567);
    printf("%lf\n", 123.56);
    printf("%lf\n", 123.);
    return 0;
}
