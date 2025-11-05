#include "string_function.h"

// 字符串比较函数,比较str1和str2指向的字符串
// 返回值为0表示相等,大于0表示str1大于str2,小于0表示str1小于str2
int string_compare(char *str1, char *str2)
{
    for( ; *str1 == *str2; str1++, str2++)
    {
        if(*str1 == '\0')
            return 0;
    }
    return *str1 - *str2;
}

//  字符串复制函数,将src指向的字符串复制到dest指向的内存中
// 包括字符串结束符'\0'
void string_copy(char *dest, char *src)
{
    while(*dest++ = *src++)
        ;
}

// 字符串长度计算函数实现
int string_length(char *str)
{
    int length = 0;
    while(*str != '\0')
    {
        length++;
        str++;
    }
    return length;
}

// 字符串连接函数实现
void string_concat(char *dest, char *src)
{
    // 先找到dest字符串的末尾
    while(*dest != '\0')
    {
        dest++;
    }
    
    // 将src字符串复制到dest的末尾
    while(*dest++ = *src++)
        ;
}

// 字符串查找字符函数实现
int string_find_char(char *str, char ch)
{
    int position = 0;
    while(*str != '\0')
    {
        if(*str == ch)
        {
            return position;  // 找到字符，返回位置
        }
        str++;
        position++;
    }
    return -1;  // 未找到，返回-1
}