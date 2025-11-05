# Makefile for string function project

# 编译器
CC = gcc

# 编译选项
CFLAGS = -Wall -g

# 目标可执行文件
TARGET = main.exe

# 源文件
SOURCES = main.c string_function.c

# 头文件
HEADERS = string_function.h

# 默认目标
all: $(TARGET)

# 编译规则
$(TARGET): $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCES)

# 运行程序
run: $(TARGET)
	./$(TARGET)

# 清理生成的文件
clean:
	del $(TARGET)

# 声明伪目标
.PHONY: all run clean