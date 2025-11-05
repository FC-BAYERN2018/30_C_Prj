#include <stdio.h>

// 结构体：一种自定义的数据类型,存储坐标点
struct point
{
    int x;
    int y;
};

struct rect
{
    struct point pt1;
    struct point pt2;
};

double dist,rect_area,dist_to_orgin,sqrt(double x);


int main() {
    struct point pt1 = {10, 20};
    struct point pt2 = {15, 25};
    struct rect r1 = {pt1, pt2};
    dist = sqrt((r1.pt1.x - r1.pt2.x) * (r1.pt1.x - r1.pt2.x) + (r1.pt1.y - r1.pt2.y) * (r1.pt1.y - r1.pt2.y));
    dist_to_orgin = sqrt(r1.pt1.x * r1.pt1.x + r1.pt1.y * r1.pt1.y);
    rect_area = (r1.pt2.x - r1.pt1.x) * (r1.pt2.y - r1.pt1.y);

    // printf("pt1.x = %d, pt1.y = %d\n", r1.pt1.x, r1.pt1.y);
    // printf("pt2.x = %d, pt2.y = %d\n", r1.pt2.x, r1.pt2.y);
    // printf("pt1与pt2的距离为：%f\n", dist);
    // printf("pt1到原点的距离为：%f\n", dist_to_orgin);
    // printf("矩形r1的长为：%d\n", r1.pt2.x - r1.pt1.x);
    // printf("矩形r1的宽为：%d\n", r1.pt2.y - r1.pt1.y);
    // printf("矩形r1的面积为：%f\n", rect_area);
    printf("矩形r1的左下角坐标为：%d，%d\n", r1.pt1.x, r1.pt1.y);


    return 0;
}