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
// 定义了一个名为 addpoint 的结构体函数
struct point addpoint(struct point p1, struct point p2)
{   
    //写法1
    //struct point temp;
    // temp.x = p1.x + p2.x;
    // temp.y = p1.y + p2.y;
    // return temp;
    //写法2 更简洁高效
    p1.x += p2.x;
    p1.y += p2.y;
    return p1;
}

// 测试addpoint函数 
int main()
{
    struct point pt1 = make_point(60, 20);
    struct point pt2 = make_point(15, 25);
    struct point pt3 = addpoint(pt1, pt2);
    printf("pt3.x = %d, pt3.y = %d\n", pt3.x, pt3.y);
    return 0;
}


// 测试make_point函数

// int main()
// {
//     struct point pt1 = make_point(10, 20);
//     printf("pt1.x = %d, pt1.y = %d\n", pt1.x, pt1.y);
//     return 0;
// }
