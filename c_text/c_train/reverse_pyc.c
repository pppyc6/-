/* reverse_pyc.c -- 将文件内容逆序输出到屏幕 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NAME_SIZE 41

char *s_gets(char *str, int n); 
int main()
{
    FILE *fp;
    char file_name[NAME_SIZE];
    long last, count;
    int ch;

    puts("请输入想逆序的文件名(输入回车结束):");
    while (s_gets(file_name, NAME_SIZE) && file_name[0] != '\0')
    {
        if((fp = fopen(file_name, "r")) == NULL)
        {
            fprintf(stderr, "无法以\"r\"模式打开文件%s", file_name);
            exit(EXIT_FAILURE);
        }
        fseek(fp, 0L, SEEK_END);
        last = ftell(fp);
        for (count = 1L; count <= last; count ++)
        {
            /* 回退 */
            fseek(fp, -count, SEEK_END);
            ch = getc(fp);
            putchar(ch);
        }
        putchar('\n');
        printf("文件%s已经倒序输出完成\n", file_name);
        if(fclose(fp) != 0)
            fprintf(stderr, "关闭文件%s失败\n", file_name);
        puts("请输入下一个文件(按下回车结束):");
    }

    return 0;
}
/* 老牌输入函数 */
char *s_gets(char *str, int n)
{
    char *ret_val;
    char *find;
    ret_val = fgets(str, n, stdin);
    if (ret_val)
    {
        find = strchr(str, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}