// 字符串的截断
// 读到某一特殊的数值 需要返回其位置
// c++中substr是string类的成员函数
// c++中find是string类的成员函数
// substr find的用法
// 将字符串转换为double数据
// stod能自动将字符串中的非数字元素忽略
// 从哪里开始便包含其
// 存在stod 那必然存在stoi
#include <iostream>
#include <cstring>
using namespace std;
class Solution
{
private:
    string temp;
    double r, i;

public:
    Solution(const char *p)
    {
        temp = p;
        r = stod(temp.substr(0, temp.find('+')));
        i = stod(temp.substr(temp.find('+') + 1, temp.find('i') - temp.find('+') - 1));
        cout << r << endl;
        cout << i << endl;
    }
};
int main()
{
    Solution res = "3.3+4.4i";
    return 0;
}
