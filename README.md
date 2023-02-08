# get_private
Get private members of a C++ class.

```cpp
#include "get_private.hpp"

class A {
    static int x;
    double y;
};

int A::x = 0;

//                 int &  get_A_x() { return A::x; }  // => Compilation error. Cannot access private members.
DEFINE_GET_PRIVATE(int &, get_A_x,           A::x)

//                 double A::*  get_A_y() { return &A::y; }
DEFINE_GET_PRIVATE(double A::*, get_A_y,           &A::y)

int main() {
    // A::x = 123;  // => Compilation error. Cannot access private members.
    get_A_x() = 123;

    A a;
    // a.y = 4.56;
    a.*get_A_y() = 4.56;
}
```

## Related works

- https://github.com/martong/access_private
- https://www.zhihu.com/question/521898260/answer/2394522797
- https://gist.github.com/dabrahams/1528856
