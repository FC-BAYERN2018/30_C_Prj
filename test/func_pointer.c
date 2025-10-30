#include <stdio.h>
#include <windows.h>


void greet(void (*f)(const char*)) {
    f("Hello from callback!");
}

void print_english(const char* msg) {
    printf("English: %s\n", msg);
}

void print_chinese(const char* msg) {
    printf("中文: %s\n", msg);
}

void main() {
    greet(print_english);
    greet(print_chinese);
}