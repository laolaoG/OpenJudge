// 复制构造函数
// 构造函数没有返回值 简单的语句没有赋值的操作
// 复制构造函数通常有默认的形式
// 普通函数调用复制构造函数
#include <iostream>
using namespace std;
class Sample
{
public:
    int v;
    Sample() {}
    Sample(int val)
    {
        this->v = val;
    }
    Sample(const Sample &a)
    {
        v = a.v + 2;
    }

    // 在此处补充你的代码
};
void PrintAndDouble(Sample o)
{
    cout << o.v;
    cout << endl;
}
int main()
{
    Sample a(5);
    Sample b = a;
    PrintAndDouble(b);
    Sample c = 20;
    PrintAndDouble(c);
    Sample d;
    d = a;
    cout << d.v;
    return 0;
}
