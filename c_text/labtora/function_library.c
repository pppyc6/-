// function_library.c -- 这是我自己在编写函数的定义，不用于其他。

#include "name.h"
#include <stdio.h>
#include <string.h>
#include <string.h>

int per_cent(int a, int b)
{
    int ret = a - (a / b) * b;
    return ret;
    // 这是一个很搞笑的用于代替'%'的一个函数。
}
char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;
    ret_val = fgets(st, n, stdin);
    if(ret_val)
    {
        find = strchr(st, '\n'); // 查找换行符
        if (find)
            *find  = '\0'; // 放置一个空字符
        else
            while(getchar() != '\n')
            continue; // 清理输入行

        return ret_val;
    }
}

