#include <stdio.h>
#include "string_function.h"  // 包含所有字符串工具函数的声明

int main()
{
    printf("=== 多函数演示程序 ===\n\n");
    
    // 测试字符串比较
    char str1[] = "hello";
    char str2[] = "world";
    int cmp_result = string_compare(str1, str2);
    printf("1. 字符串比较测试:\n");
    printf("   string_compare(\"%s\", \"%s\") = %d\n", str1, str2, cmp_result);
    printf("   结果: \"%s\" %s \"%s\"\n\n", str1, 
           cmp_result > 0 ? "大于" : cmp_result < 0 ? "小于" : "等于", str2);
    
    // 测试字符串长度
    int len1 = string_length(str1);
    int len2 = string_length(str2);
    printf("2. 字符串长度测试:\n");
    printf("   string_length(\"%s\") = %d\n", str1, len1);
    printf("   string_length(\"%s\") = %d\n\n", str2, len2);
    
    // 测试字符串复制
    char dest[50];
    string_copy(dest, str1);
    printf("3. 字符串复制测试:\n");
    printf("   复制前: dest = (空)\n");
    printf("   string_copy(dest, \"%s\")\n", str1);
    printf("   复制后: dest = \"%s\"\n\n", dest);
    
    // 测试字符串连接
    char concat_str[100] = "Hello, ";
    string_concat(concat_str, "World!");
    printf("4. 字符串连接测试:\n");
    printf("   原字符串: \"Hello, \"\n");
    printf("   连接 \"World!\" 后: \"%s\"\n\n", concat_str);
    
    // 测试字符查找
    char search_str[] = "programming";
    char target_char = 'g';
    int pos = string_find_char(search_str, target_char);
    printf("5. 字符查找测试:\n");
    printf("   在 \"%s\" 中查找字符 '%c'\n", search_str, target_char);
    if(pos != -1) {
        printf("   找到了！位置: %d\n", pos);
    } else {
        printf("   未找到该字符\n");
    }
    
    return 0;
}