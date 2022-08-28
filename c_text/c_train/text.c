/* text.c -- 用于测试一些函数的用法 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    long len = 0;
    if ((fp = fopen("rrr.txt", "r")) == NULL)
    {
        fprintf(stderr, "无法打开xxx.txt");
        exit(EXIT_FAILURE);
    }
    rewind(fp);
    len = ftell(fp);
    printf("%ld\n", len);
    fclose(fp);

    return 0;
}