# get_private
Get private members of a C++ class.

```cpp
class A {
    int x;
};

DEFINE_GET_PRIVATE(int A::*, get_A_x, &A::x)

int main() {
    A a;
    a.*get_A_x() = 123;
}
```

## Related works

- https://github.com/martong/access_private
- https://www.zhihu.com/question/521898260/answer/2394522797
- https://gist.github.com/dabrahams/1528856
