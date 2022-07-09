#include <iostream>
#include <string>

#include "get_private.hpp"

class A {
    int x;
    template<typename T, typename U>
    auto foo(T a, U b) -> decltype(a + b) { return a + b; }
    static double y;
    static int bar(int a, int b) { return a * b; }
    static double bar(double a) { return a * a; }
public:
    void check() const { std::cout << "x=" << x << " y=" << y << std::endl; }
};

double A::y{};

DEFINE_GET_PRIVATE(int A::*, get_A_x, &A::x)
DEFINE_GET_PRIVATE(double (A::*)(int, double), get_A_foo, &A::foo)
DEFINE_GET_PRIVATE(std::string (A::*)(std::string, std::string), get_A_foo2, &A::foo)
DEFINE_GET_PRIVATE(double *, get_A_y, &A::y)
DEFINE_GET_PRIVATE(int (*)(int, int), get_A_bar, &A::bar)
DEFINE_GET_PRIVATE(double (*)(double), get_A_bar2, &A::bar)

int main() {
    A a;
    a.*get_A_x() = 123;
    *get_A_y() = 4.56;
    std::cout << (a.*get_A_foo())(1, 2) << std::endl;
    std::cout << (a.*get_A_foo2())("Hello", "World") << std::endl;
    std::cout << (*get_A_bar())(3, 4) << std::endl;
    std::cout << (*get_A_bar2())(5.55) << std::endl;
    a.check();
}
