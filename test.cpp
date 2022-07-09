#include <iostream>

#include "get_private.hpp"

class A {
    int x;
    double foo(double a) { return a * a; }
    int foo(int a) { return a * a; }
    static double y;
    static int bar(int a, int b) { return a + b; }
public:
    void check() const { std::cout << "x=" << x << " y=" << y << std::endl; }
};

double A::y{};

DEFINE_GET_PRIVATE(int A::*, get_A_x, &A::x);
DEFINE_GET_PRIVATE(double (A::*)(double), get_A_foo, &A::foo);
DEFINE_GET_PRIVATE(double *, get_A_y, &A::y);
DEFINE_GET_PRIVATE(int (*)(int, int), get_A_bar, &A::bar);

int main() {
    A a;
    a.*get_A_x() = 123;
    std::cout << (a.*get_A_foo())(3.14) << std::endl;
    *get_A_y() = 4.56;
    std::cout << (*get_A_bar())(1, 2) << std::endl;
    a.check();
}
