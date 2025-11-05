/*
 *  io_function.c
 *  一次体验 C 语言全部常用输入/输出函数
 */
#include <stdio.h>
#include <string.h>

#define BUF 128

int main(void)
{
    /* 1. printf / putchar / puts **************************************/
    printf("=== 1. 标准输出演示 ===\n");  // 打印字符串,格式化输出到标准输出
    putchar('A');                       // 打印字符 'A',输出一个字符
    putchar('\n');                      // 打印换行符    
    puts("test the puts() fucntion!");          //输出一个字符串并自动换行
    printf("printf: int=%d, float=%.2f, string=%s\n", 123, 3.14, "hello");

    /* 2. scanf / getchar / fgets *************************************/
    printf("\n=== 2. 标准输入演示 ===\n");

    int    i;
    double f;
    char   c;
    char   line[BUF];

    printf("请输入一个整数：");
    scanf("%d", &i);

    printf("请输入一个浮点数：");
    scanf("%lf", &f);

    /* 吃掉前面残留的换行，防止被 getchar 吃掉 */
    getchar();

    printf("请输入一个字符：");
    c = getchar();

    getchar(); /* 吃掉回车 */

    printf("请输入一行字符串（fgets 安全读取）：");
    fgets(line, sizeof(line), stdin);
    //int index = strcspn(line, "\n")   //扫描 line，返回第一次出现 '\n' 的下标。
    line[strcspn(line, "\n")] = '\0';   /* 把末尾 '\n'换成'\0' 等效于 line[index] = '\0' */ 

    /* 3. 废弃函数 gets（默认关闭） ************************************/
#if 0   /* 改成 1 可体验，但会收到编译警告 */
    char unsafe[BUF];
    printf("再输入一行（gets，已废弃）：");
    gets(unsafe);          /* 危险！仅演示 */
    printf("gets 读到的内容：[%s]\n", unsafe);
#endif

    /* 4. 汇总打印 *****************************************************/
    printf("\n=== 3. 汇总打印 ===\n");
    printf("整数  : %d\n", i);
    printf("浮点数: %g\n", f);
    printf("字符  : %c\n", c);
    printf("字符串: [%s]\n", line);

    /* 5. 文件 I/O：fprintf / fscanf / fputs / fgets / fputc *********/


    const char *fname = "demo_out.txt";
    //打开文件 FILE *fopen(const char *pathname, const char *mode);
    //mode: "r" 只读模式，文件不存在则报错
    //      "w" 写入模式，文件不存在则创建，存在则清空内容
    //      "a" 追加模式，文件不存在则创建，存在则在末尾追加
    //      "r+" 读写模式，文件不存在则报错
    //      "w+" 读写模式，文件不存在则创建，存在则清空内容
    //      "a+" 读写模式，文件不存在则创建，存在则在末尾追加
    FILE *fp = fopen(fname, "w+");              /* 读写模式，文件不存在则创建 */
    if (!fp) {
        perror("fopen");
        return 1;
    }
    //int fprintf(FILE *stream, const char *format, ...);
    //把格式化数据写入文件流 stream， 
    //成功 → 实际写入的字符总数（不含结尾 \0）；
    //失败 → 负值（通常是 -1），并置 errno。
    fprintf(fp, "整数=%d 浮点数=%g 字符=%c 字符串=%s\n", i, f, c, line);

    /* 把刚才写入的内容读回来 */
    rewind(fp); /* 回到文件头 */

    int    fi;
    double ff;
    char   fc;
    char   fline[BUF];
    //int fscanf(FILE *stream, const char *format, ...);
    //从任意输入流（文件、标准输入、管道、socket 等）按指定格式读取数据，存到后续指针参数所指向的变量里。
    //format: "整数=%d 浮点数=%lg 字符=%c 字符串=%[^\n]\n"
    //      %d 整数
    //      %lg 浮点数
    //      %c 字符
    //      %[^\n] 字符串，直到遇到换行符为止
    /*| 说明符            | 期望输入                  | 存储目标类型         | 示例                                               |
| -------------- | --------------------- | -------------- | ------------------------------------------------ |
| `%d`           | 十进制有符号整数                 | `int *`        | `int x; fscanf(fp,"%d",&x);`                     |
| `%u`           | 十进制无符号整数                 | `unsigned *`   | `unsigned u; fscanf(fp,"%u",&u);`                |
| `%o`           | 八进制整数                      | `unsigned *`   |                                                  |
| `%x`           | 十六进制整数                     | `unsigned *`   |                                                  |
| `%f`/`%e`/`%g` | 浮点数                         | `float *`      | `float f; fscanf(fp,"%f",&f);`                   |
| `%lf`          | 浮点数                         | `double *`     | `double d; fscanf(fp,"%lf",&d);`                 |
| `%c`           | **不跳过空白**的单个字符         | `char *`       | `char c; fscanf(fp," %c",&c);` 注意空格可跳过空白         |
| `%s`           | **跳过前导空白**的**非空白字符串**  | `char *`（需足够大） | `char s[100]; fscanf(fp,"%99s",s);`              |
| `%[...]`       | 自定义字符集                      | `char *`       | `char tok[64]; fscanf(fp,"%63[^,]",tok);` 读到逗号为止 |
| `%*`           | 抑制赋值，只匹配不存储             | ——             | `fscanf(fp,"%*d");` 吞掉一个整数不保存                    |

    */
    fscanf(fp, "整数=%d 浮点数=%lg 字符=%c 字符串=%[^\n]\n",
          &fi, &ff, &fc, fline);

    printf("\n=== 4. 从文件读回 ===\n");
    printf("fscanf 读回：%d %g %c [%s]\n", fi, ff, fc, fline);

    /* 再演示 fputc / fputs */
    fputc('\n', fp);
    fputs("This line was written by fputs()\n", fp);

    fclose(fp);

    /* 6. 再次用 fgets 把最后一行读出来验证 ****************************/
    fp = fopen(fname, "r");
    if (!fp) return 1;

    printf("\n=== 5. 用 fgets 把最后一行读出来 ===\n");
    while (fgets(line, sizeof(line), fp))
        fputs(line, stdout); /* 逐行回显 */

    fclose(fp);
    return 0;
}