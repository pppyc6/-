// lab.c -- 这是一个c语言实验室主要用于调试用的吧了，没什么其它用。

#include "name.h" // 自己定义的函数。
#include <stdio.h> // 基础的c函数如printf、scanf等等。 
#include <string.h> // 处理字符串。
#include <stdint.h> // 可移植类型，帮助声明int等，包含新的类型如：int_32t等，还有最小整数类型：int_least8_t，最快整数类型：int_fast8_t等，最大整数类型：intmax_t等，最大无符号整数类型：unitmax_t等。
#include <inttypes.h> // 可移植类型，帮助在使用类型printf函数时定义是使用%d还是%ld之类的。PRId32是字符串宏，代表打印32位有符号值的合适转换说明（如d或l）。
#include <complex.h> // 复数的一个头文件。
#include <limits.h> // 整型限制。
#include <float.h> // 浮点数限制。
#include <stdbool.h> // 布尔运算。
#include <math.h> // 如其名。
#include <ctype.h> // 检查大小写字符之类的等等,处理字符。
#include <stdlib.h> // rand, free, mrand, malloc、calloc等原型名。
#include <time.h> // time()原型。
#include <stdarg.h> // 可以设置可变参量的函数。
// #include <tgmath.h> // 提供泛式表达式如sqrt()可以用int、double、float等等，还有个方法就是用_Generic宏直接改函数就好了，本质是一样的。
// _Noreturn有这个标识符的函数就直接结束不会返回main()。
#include <assert.h> // 辅助测试小型库，检验几个关键值是不是对的，不对程序终止。
#include <stdarg.h> // 变参函数。记录一下变参宏:__VA_ARGS__

int main()
{
    int a, b;
    per_cent(a, b);
    
    return 0;
}