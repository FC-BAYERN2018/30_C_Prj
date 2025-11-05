#include <stdio.h>
int main(void)
{
    int A = 100;
    float B = 200.051; //200.051 在 float 中实际被存储为 200.050994873046875，所以 fprintf 打印的是这个近似值。
    double C = 200.051; //200.051 在 double 中实际被存储为 200.050999999999990296，所以 fprintf 打印的是这个近似值。
    
    char chr ='X';
    char str[100] = "Hello World";
    const char *filename = "IO_test.txt";
    FILE *fp = fopen(filename, "w+");
    if (!fp) {
        perror("fopen");
        return 1;
    }
    fprintf(fp, "A=%d\b",A);
    fprintf(fp, "B=%f\n",B); // 保留3位小数, 实际存储值为 200.050994873046875
    fprintf(fp, "B=%.3f\n",B);
    fprintf(fp, "C=%f\n",C);
    fprintf(fp, "C=%.3f\n",C); // 保留3位小数, 实际存储值为 200.050999999999990296
    fprintf(fp, "%c\n", chr);
    fprintf(fp, "%s\n", str);
    fclose(fp);
}