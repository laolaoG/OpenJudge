// 003:好怪异的返回值
// 子函数返回的是对数组元素的引用 左值
// int a[] = {1,2,3} 数组a的大小为3
#include <iostream>
using namespace std;
int &getElement(int * a, int i)
{
    return a[i];
}
int main()
{
    int a[] = {1,2,3};
    getElement(a,1) = 10;
    cout << a[1] ;
    return 0;
}
