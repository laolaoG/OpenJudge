// 001:简单的swap
// A类中存在成员变量
// 在函数swap中对A类进行引用来修改其中的成员变量
#include <iostream>
using namespace std;
class A
{
public:
    int x;
    int getX() { return x; }
};
void swap(A &a, A &b)
{
    int  tmp = a.x;
    a.x = b.x;
    b.x = tmp;
}
int main()
{
    A a,b;
    a.x = 3;
    b.x = 5;
    swap(a,b);
    cout << a.getX() << "," << b.getX();
    return 0;
}
