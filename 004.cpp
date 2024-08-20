// 神秘的数组初始化
// new int返回值为int*类型
// new int[6] 返回值为int*类型 不过分配的空间为大小为6的数组
// a[2]指向123
// a[3]指向int[6]
#include <iostream>
using namespace std;

int main()
{
    // 数组元素中的每个元素都是int *类型（int、int[]）
    int * a[] = {
        nullptr,nullptr,new int,new int[6]
    };

    *a[2] = 123;
    a[3][5] = 456;
    if(! a[0] ) {
        cout << * a[2] << "," << a[3][5];
    }
    return 0;
}
