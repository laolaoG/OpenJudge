// 如果类的实例没有被初始化
// 实例 = 10
// 会调用构造函数
#include <iostream>
using namespace std;
class A
{
public:
    int val;

    A(int val)
    {
        this->val = val;
    }
    A() { val = 123; }
    A &GetObj()
    {
        return *this;
    }
};
int main()
{
    int m, n;
    A a;
    cout << a.val << endl;
    while (cin >> m >> n)
    {
        a.GetObj() = m;
        cout << a.val << endl;
        a.GetObj() = A(n);
        cout << a.val << endl;
    }
    return 0;
}
