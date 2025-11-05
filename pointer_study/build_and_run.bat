@echo off
echo 正在编译程序...
gcc -o main.exe main.c string_function.c

if %errorlevel% equ 0 (
    echo 编译成功！正在运行程序...
    echo.
    .\main.exe
) else (
    echo 编译失败！
)

pause