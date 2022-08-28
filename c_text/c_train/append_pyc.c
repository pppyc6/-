/* append_pyc -- 文件末尾添加源文件 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFSIZE 4096
#define FILE_NAME 81

char *s_gets(char *st, int n);
int append(FILE *sourse, FILE *dest);
int main(int argc, char *argv[])
{
    FILE *fs; // 源文件指针
    FILE *fa; // 添加文件指针
    char file_src[FILE_NAME];
    char file_app[FILE_NAME];
    int files = 0;
    int ch;
    puts("请输入需要目标文件名（输入回车结束）：");
    s_gets(file_app, FILE_NAME);
    if ((fa = fopen(file_app, "a+")) == NULL)
    {
        fprintf(stderr, "错误未正确打开%s", file_app);
        exit(EXIT_FAILURE);
    }
    if(setvbuf(fa, NULL, _IOFBF, BUFSIZE) != 0)
    {
        fprintf(stderr, "无法为%s创建缓冲区", file_app);
        exit(EXIT_FAILURE);
    }
    puts("请输入第一个源文件吧：");
    while (s_gets(file_src, FILE_NAME) && file_src[0] != '\0')
    {   
        if(strcmp(file_app, file_src) == 0)
        {
            puts("目标文件不能是源文件");
            continue;
        }
            else if((fs = fopen(file_src, "r")) == NULL)
        {
            fprintf(stderr, "无法打开%s源文件", file_src);
            continue;
        }
        else
        {   if(setvbuf(fs, NULL, _IOFBF, BUFSIZE) != 0)
            {
                fprintf(stderr, "不能为%s创建缓冲区", file_src);
            }
        }
        if(ferror(fa) != 0)
        {
            fprintf(stderr, "无法以\"a+\"打开%s文件", file_app);
            continue;
        }
        if (ferror(fs) != 0)
        {
            fprintf(stderr,"无法以\"r\"打开%s文件", file_src);
            continue;
        }
        
        append(fs, fa);
        files ++;
        printf("%s已经输入%s\n", file_src, file_app); 
        puts("请输入下一个文件（输入回车结束）：");
    }
    printf("共有%d个文件被添加\n", files);
    printf("%s:", file_app);
    rewind(fa);
    while((ch = getc(fa)) != EOF)
        putchar(ch);
    fclose(fa);
    
        return 0;
}
char * s_gets(char * st , int n)
{
    char * ret_val;
    char * find;
    ret_val = fgets(st, n, stdin);
    if(ret_val)
    {
        find = strchr(st, '\n');
        if(find)
            *find = '\0';
        else
            while(getchar() != '\n')
                continue;
            
    }
    return ret_val;
}
int append(FILE * sourse, FILE * dest)
{
    static char buffer[BUFSIZE];
    int bytes;

    while((bytes = fread(buffer, sizeof(char), BUFSIZE, sourse)) > 0 )
    fwrite(buffer, sizeof(char), BUFSIZE, dest);
    return bytes;
}