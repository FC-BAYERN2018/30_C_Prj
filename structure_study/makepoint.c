#include <stdio.h>

// 定义结构体
struct point
{
    int x;
    int y;
};

// 定义了一个名为 make_point 的结构体函数
struct point make_point(int x, int y)
{
    struct point temp;
    temp.x = x;
    temp.y = y;
    return temp;
}

int main()
{
    struct point pt1 = make_point(10, 20);
    printf("pt1.x = %d, pt1.y = %d\n", pt1.x, pt1.y);
    return 0;
}
