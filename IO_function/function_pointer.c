#include <stdio.h>

/* ① 定义两个“签名相同”的函数 */
int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }
int div(int a, int b) { return a / b; }



int main(void)
{
    /* ② 声明函数指针并初始化 */
    // int (*op)(int, int) = add;   // 指向 add
    typedef int (*MathOp)(int, int);
    MathOp op = add;

    printf("3 + 5 = %d\n", op(3, 5));  // 输出 8

    op = sub;                    // ③ 运行时改指向 sub
    printf("9 - 5 = %d\n", op(9, 5));  // 输出 -2

    op = mul;                    // ④ 运行时改指向 mul
    printf("3 * 5 = %d\n", op(3, 5));  // 输出 15

    op = div;                    // ⑤ 运行时改指向 div
    printf("10 / 5 = %d\n", op(10, 5));  // 输出 1

    return 0;
}