// 002:难一点的swap
// 主函数中存在变量 并且有指针指向这些变量
// 在swap函数中 如果是值复制的话 原先的指针并不会修改指向 所以需要引用
#include <iostream>
using namespace std;

void swap(int *&a,  int *&b)
{
    int * tmp = a;
    a = b;
    b = tmp;
}
int main()
{
    int a = 3,b = 5;
    int * pa = & a;
    int * pb = & b;
    swap(pa,pb);
    cout << *pa << "," << * pb;
    return 0;
}
