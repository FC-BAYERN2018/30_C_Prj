#ifndef STRING_FUNCTION_H
#define STRING_FUNCTION_H

// 字符串工具函数库 - 函数声明

// 字符串比较函数
// 返回值: 0表示相等, >0表示str1大于str2, <0表示str1小于str2
int string_compare(char *str1, char *str2);

// 字符串复制函数
// 将src字符串复制到dest中
void string_copy(char *dest, char *src);

// 字符串长度计算函数
// 返回字符串的长度（不包括结束符'\0'）
int string_length(char *str);

// 字符串连接函数
// 将src字符串连接到dest字符串的末尾
void string_concat(char *dest, char *src);

// 字符串查找函数
// 在str中查找字符ch，返回第一次出现的位置，未找到返回-1
int string_find_char(char *str, char ch);

#endif // STRING_FUNCTION_H
