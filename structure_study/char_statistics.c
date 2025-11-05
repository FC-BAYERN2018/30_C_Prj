#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// 定义单词最大长度
#define MAXWORD 100

// 定义关键字结构体
typedef struct key {
    char *word;  // 关键字字符串
    int count;   // 关键字出现次数
} Key;

/**
 * @brief 按字典序排序的C语言关键字表
 * @note 必须保持字典序排序，以便二分查找算法正确工作
 */
Key keytab[] = {
    {"auto", 0},
    {"break", 0},
    {"case", 0},
    {"char", 0},
    {"const", 0},
    {"continue", 0},
    {"default", 0},
    {"double", 0},
    {"int", 0},
    {"static", 0},
    {"typedef", 0},
    {"void", 0},
    {"volatile", 0},
    {"while", 0}
};

// 函数声明
int getword(char *word, int limit);
int binarysearch(char *word, Key *keytab, int n);
//////////////////////////////////////////////////////////////
/**
 * @brief 主函数 - 统计C语言关键字在输入文本中的出现次数
 * 
 * 该函数从标准输入读取单词，检查是否为C语言关键字，并统计每个关键字出现的次数，
 * 最后输出统计结果。
 * 
 * @return int 程序执行状态码，0表示正常结束
 */
int main(void)
{
    // 计算keytab数组的元素个数，通过总大小除以单个元素大小
    // - sizeof(keytab) 计算整个结构体数组占用的总字节数
    // - sizeof(keytab[0]) 计算单个 Key 结构体占用的字节数
    // - 两者相除得到数组中定义的关键字数量（在你的代码中是14个）
    int n = sizeof(keytab) / sizeof(keytab[0]);
    
    // 用于存储从输入读取的单词的缓冲区
    char word[MAXWORD];

    // 主循环：从输入读取单词直到遇到文件结束符
    while (getword(word, MAXWORD) != EOF) {
        // 只处理以字母开头的单词（排除数字、符号等）
        if (isalpha(word[0])) {
            // 使用二分查找算法在关键字表中查找当前单词
            int index = binarysearch(word, keytab, n);
            
            // 如果找到匹配的关键字（index >= 0），增加其计数
            if (index >= 0) {
                keytab[index].count++;
            }
        }
    }
    
    // 输出统计结果：只显示出现次数大于0的关键字及其计数
    printf("\nC语言关键字统计结果：\n");
    printf("-----------------------------------\n");
    for (int i = 0; i < n; i++) {
        if (keytab[i].count > 0) {
            printf("%-10s: %3d\n", keytab[i].word, keytab[i].count);
        }
    }
    printf("-----------------------------------\n");
    
    return 0;
}
//////////////////////////////////////////////////////////////
/**
 * @brief 使用二分查找算法在关键字表中查找指定单词
 * 
 * @param word 要查找的目标单词
 * @param keytab 关键字表数组
 * @param n 关键字表中的元素数量
 * @return 找到时返回单词在数组中的索引，未找到时返回-1
 */
int binarysearch(char *word, Key *keytab, int n) {
    int cond;          // 字符串比较结果
    int low = 0;       // 搜索范围起始索引
    int high = n - 1;  // 搜索范围结束索引
    int mid;           // 中间索引
    
    // 当搜索范围有效时继续查找
    while (low <= high) {
        // 计算中间索引（避免整数溢出的写法）
        mid = low + (high - low) / 2;
        
        // 比较目标单词与中间位置的关键字
        cond = strcmp(word, keytab[mid].word);
        
        if (cond < 0) {
            // 目标在左半部分
            high = mid - 1;
        } else if (cond > 0) {
            // 目标在右半部分
            low = mid + 1;
        } else {
            // 找到目标，返回索引
            return mid;
        }
    }
    
    // 未找到目标
    return -1;
}