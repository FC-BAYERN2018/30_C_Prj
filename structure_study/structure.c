#include <stdio.h>

// 结构体：一种自定义的数据类型,存储坐标点
struct point
{
    int x;
    int y;
};

int main() {
    struct point p1 = {10, 20};
    printf("p1.x = %d, p1.y = %d\n", p1.x, p1.y);
    return 0;
}