/* randbin_pyc.c -- 用于检查创建的二进制文件的数据 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NAME_SIZE 81

char *s_gets(char *str, int n);
int main()
{
    FILE *fp;
    long pos = 0;
    char name[NAME_SIZE];
    long stdsize;

    puts("请输入需要展示的文件名");
    while(s_gets(name, NAME_SIZE) && name[0] != '\0')
    {
        if((fp = fopen(name, "rb")) == NULL)
        {
            fprintf(stderr, "无法正确打开文件%s", name);
            continue;
        }
        else
        {
            printf("请输入文件%s的数据大小", name);
            scanf("%ld", &stdsize);
            rewind(fp);
            while (fseek(fp, pos, SEEK_SET) != 0)
            {  
                fread(, stdsize, 1, fp);

                pos += stdsize;
            }
           
            
        }
    }

    return 0;
}
char *s_gets(char *str, int n)
{
    char *ret_val;
    char *find;

    ret_val = fgets(str, n, stdin);
    if(ret_val)
    {
        find = strchr(str, '\n');
        if(find)
            *find = '\0';
        else
            while(getchar() != '\n')
            continue;
    }
    return ret_val;
}