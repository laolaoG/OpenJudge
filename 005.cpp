#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <cstdlib>
using namespace std;

class Student
{
    string name;
    int age;
    int num;
    int av1, av2, av3, av4;
    double average;

public:
    void input()
    {
        getline(cin, name, ',');
        char c;
        cin >> age >> c >> num >> c >> av1 >> c >> av2 >> c >> av3 >> c >> av4;
    }
    void calculate()
    {
        average = (av1 + av2 + av3 + av4) / 4;
    }
    void output()
    {
        cout << name << ',' << age << ',' << num << ',' << average;
    }
    // 在此处补充你的代码
};

int main()
{
    Student student;     // 定义类的对象
    student.input();     // 输入数据
    student.calculate(); // 计算平均成绩
    student.output();    // 输出数据
}
