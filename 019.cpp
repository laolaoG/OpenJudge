// 如果以字符数组接收字符
// 如何打印
// 如果使用cout打印字符数组 遇到\0停止
// cout 无法打印空指针
// char* 变量可以传入const char*变量
// 指针是否为空 或者指针相等的判断
// strcmp函数 比较字符串的长度
// strcat函数
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
class Mystring
{
private:
    char *str;

public:
    Mystring()
    {
        str = new char[1];
        str[0] = '\0';
    }
    Mystring(const char *p)
    {
        str = new char[strlen(p) + 1]; // 如此便可保证内存空间分配合理 的确不需要memset 如果使用也没有问题
        strcpy(str, p);
    }
    Mystring(const Mystring &p) // 复制构造函数
    {
        if (!p.str)
            this->str = nullptr;
        else
        {
            str = new char[strlen(p.str) + 1];
            strcpy(str, p.str);
        }
    }
    // char &operator[](int i)
    // {
    //     return str[i];
    // }
    Mystring &operator=(const Mystring &p)
    {
        if (str == p.str)
            return *this;
        if (!str)
            delete[] str;
        if (!p.str)
            str = nullptr;
        else
        {
            str = new char[strlen(p.str) + 1];
            strcpy(str, p.str);
        }
        return *this;
    }
    char &operator[](int n)
    {
        return str[n];
    }
    friend ostream &operator<<(ostream &os, const Mystring &p)
    {
        os << p.str;
        return os;
    }
    friend Mystring operator+(const Mystring &a, const Mystring &p)
    { // 字符串相加函数
        char *temp = new char[strlen(a.str) + strlen(p.str) + 1];
        strcpy(temp, a.str);
        strcat(temp, p.str);
        return Mystring(temp);
    }
    Mystring &operator+=(const Mystring &a)
    {
        char *temp = a.str;
        strcat(str, a.str);
        return *this;
    }
    //
    friend bool operator>(const Mystring &s1, const Mystring &s2)
    {
        if (strcmp(s1.str, s2.str) > 0)
            return true;
        else
            return false;
    }
    friend bool operator<(const Mystring &s1, const Mystring &s2)
    {
        if (strcmp(s1.str, s2.str) < 0)
            return true;
        else
            return false;
    }
    friend bool operator==(const Mystring &s1, const Mystring &s2)
    {
        if (strcmp(s1.str, s2.str) == 0)
            return true;
        else
            return false;
    }
    char *operator()(int start, int length)
    {
        char *temp = new char[length + 1];
        for (int i = start; i < start + length; i++)
        {
            temp[i - start] = str[i];
        }
        temp[length] = '\0';
        return temp;
    }
    ~Mystring()
    {
        if (str)
            delete[] str;
    }
};

int CompareString(const void *e1, const void *e2)
{
    Mystring *s1 = (Mystring *)e1;
    Mystring *s2 = (Mystring *)e2;
    if (*s1 < *s2)
        return -1;
    else if (*s1 == *s2)
        return 0;
    else
        return 1;
}

int main()
{
    Mystring s1("abcd-"), s2, s3("efgh-"), s4(s1);
    // SArray数组的成员变量都是Mystring类嘛
    // Mystring类的实例化
    Mystring SArray[4] = {"big", "me", "about", "take"};
    cout << "1. " << s1 << s2 << s3 << s4 << endl;
    s4 = s3;
    s3 = s1 + s3;
    cout << "2. " << s1 << endl;
    cout << "3. " << s2 << endl;
    cout << "4. " << s3 << endl;
    cout << "5. " << s4 << endl;
    s2 = s1;
    s1 = "ijkl-";
    s1[2] = 'A';
    cout << "7. " << s2 << endl;
    cout << "8. " << s1 << endl;
    s1 += "mnop";
    cout << "9. " << s1 << endl;
    s4 = "qrst-" + s2; // 将字符串自动转换为构造函数
    cout << "10. " << s4 << endl;
    s1 = s2 + s4 + " uvw " + "xyz";
    cout << "11. " << s1 << endl;
    qsort(SArray, 4, sizeof(Mystring), CompareString);
    for (int i = 0; i < 4; i++)
    {
        cout << SArray[i] << endl;
    }
    // s1的从下标0开始长度为4的子串
    cout << s1(0, 4) << endl;
    // s1的从下标5开始长度为10的子串
    cout << s1(5, 10) << endl;
    return 0;
}
