/* reducto_pyc -- 用于无法找回的压缩 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 81

int reducto(FILE *src, char name[]);
char *s_gets(char str[], int n);
int main(int argc, char *argv[])
{  
    FILE *src; // 待压缩文件
    char file_src[LEN];
    int files = 0;

    puts("请输入待压缩的文件名：");
    while (s_gets(file_src, LEN) && file_src[0] != '\0')
    {
        if((src = fopen(file_src, "r")) == NULL)
        {
            fprintf(stderr, "无法打开待压缩文件");
            continue;
        }
        if(reducto(src, file_src) != 0)
        {
            fprintf(stderr,"无法压缩%s", file_src);
            continue;
        }
        files ++;
    }
    printf("已经压缩%d个文件", files);
    return 0;
}
int reducto(FILE *src, char name[])
{
    int ch;
    int count = 0;
    FILE *dest;
    char red_name[LEN];
    char *p;
    // 检测文件名有没有过长
    if(sizeof(name) / strlen(name) > LEN)
    {
        fprintf(stderr, "文件名过长");
        return -2;
    }
    // 复制文件名，并创建以.red为后缀名的压缩文件
    strncpy(red_name, name, LEN - 5);
    if((p = strchr(red_name, '.')) != NULL)
        *p = '\0';
    red_name[LEN - 5] = '\0';
    strcat(red_name, ".red");
    if ((dest = fopen(red_name, "w")) == NULL)
    {
        fprintf(stderr, "无法生成压缩文件%s",red_name);
        return -1;
    }
    // 复制1/3的字符
    while((ch = getc(src)) != EOF)
    {
        if (count % 3 == 0)
            putc(ch, dest);
        count ++;
    }
    printf("已生成%s", red_name);
    if(fclose(dest) != 0)
    {
        fprintf(stderr, "无法关闭%s", red_name);
        return -3;
    }
    return 0;
}
// 文件名老牌输入函数
char *s_gets(char str[], int n)
{
    char *ret_val;
    char *find;

    ret_val = fgets(str, n, stdin);
    if (ret_val)
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