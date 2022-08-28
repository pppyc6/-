/* manybook_prime.c -- 包含多本书的图书目录 */
#include <stdio.h>
#include <string.h>
char *s_gets(char *str, int n);
#define MAXTITL 41
#define MAXAUTL 41
#define MAXBKS 101 // 书籍的最大数量
struct book
{
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};
int main()
{
    struct book library[MAXBKS];
    int count = 0;
    int index;
    puts("Please enter the book title:");
    puts("Press [enter] at the start of a line to stop");
    while(count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL && library[count].title[0] != '\0')
    {
        puts("Now enter the author:");
        s_gets(library[count].author, MAXAUTL);
        puts("Now enter the value:");
        scanf("%f", &library[count].value);
        while(getchar() != '\n')
            continue;
        puts("Enter the next tile:");
        count ++;
    }
    if(count > 0)
    {
        puts("Here is the list of your books:");
        for(index = 0; index < count; index ++)
            printf("%s by %s: $%.2f.\n", library[index].title,
            library[index].author, library[index].value);
    }
    else
        puts("No book? Too bad.");

    return 0;
}
char *s_gets(char *str, int n)
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