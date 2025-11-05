#include <stdio.h>

// 定义结构体
struct point
{
    int x;
    int y;
};
// 定义结构体rect,其中的元素本身也是一个结构体
struct rect
{
    struct point pt1;
    struct point pt2;
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

int prinrect(struct point p, struct rect r)
{
    return p.x >= r.pt1.x && p.x < r.pt2.x
        && p.y >= r.pt1.y && p.x < r.pt2.y;
}
#define min(a,b) (a<b) ? (a):(b)
#define max(a,b) (a>b) ? (a):(b)

//cannorect 函数，将矩形坐标规范化
struct rect cannorect(struct rect r)
{
    struct rect temp;

    temp.pt1.x = min(r.pt1.x, r.pt2.x);
    temp.pt1.y = min(r.pt1.y, r.pt2.y);
    temp.pt2.x = max(r.pt1.x, r.pt2.x);
    temp.pt2.y = min(r.pt1.y, r.pt2.y);
    return temp;

}

// 结构体指针


// 测试结构体指针 
int main()
{   
    struct point *pp;
    struct point origin = {60, 20}; //结构体初始化应该使用花括号{}，而不是圆括号()
    pp = &origin;
    printf("origin.x = %d, origin.y = %d\n", pp->x, pp->y);
    return 0;
}


// 测试addpoint函数 
// int main()
// {
//     struct point pt1 = make_point(60, 20);
//     struct point pt2 = make_point(15, 25);
//     struct point pt3 = addpoint(pt1, pt2);
//     printf("pt3.x = %d, pt3.y = %d\n", pt3.x, pt3.y);
//     return 0;
// }


// 测试make_point函数

// int main()
// {
//     struct point pt1 = make_point(10, 20);
//     printf("pt1.x = %d, pt1.y = %d\n", pt1.x, pt1.y);
//     return 0;
// }
