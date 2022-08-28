/* book_prime.c -- 一本书的目录 */
#include <stdio.h>
#include <string.h>
char *s_gets(char *str, int n);

#define MAXTITL 41 // 书名的最大长度 + 1
#define MAXAUTL 31 // 作者姓名的最大长度 + 1
struct book
{
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

int main()
{
    struct book library; // 声明library是个book类型变量
    puts("Please enter the book title:");
    s_gets(library.title, MAXTITL);
    puts("Now enter the author:");
    s_gets(library.author, MAXAUTL);
    puts("Now enter the value:");
    scanf("%f", &library.value);
    printf("%s by %s $%.2f\n", library.title, library.author, library.value);
    puts("Done");

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