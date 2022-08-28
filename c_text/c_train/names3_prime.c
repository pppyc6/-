/* names3_prime.c -- 使用指针和malloc() */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SLEM 81
struct namect
{
    char *fname;
    char *lname;
    int letters;
};
void getinfo(struct namect *pst); 
void makeinfo(struct namect *pst);
void showinfo(const struct namect *pst);
void cleanup(struct namect *pst);
char *s_gets(char *str, int n);
int main()
{
    struct namect person;

    getinfo(&person);
    makeinfo(&person);
    showinfo(&person);
    cleanup(&person);

        return 0;
}
void getinfo(struct namect *pst)
{
    char temp[SLEM];
    puts("Please enter your first name.");
    s_gets(temp, SLEM);
    // 分配内存以储存名
    pst->fname = (char *)malloc(strlen(temp + 1));
    // 把名拷贝到动态分配的内存中
    strcpy(pst->fname, temp);
    puts("Please enter your last name.");
    s_gets(temp, SLEM);
    pst->lname = (char *)malloc(strlen(temp + 1));
    strcpy(pst->lname, temp);
}
void makeinfo(struct namect *pst)
{
    pst->letters = strlen(pst->fname) +strlen(pst->lname);
}
void showinfo(const struct namect *pst)
{
    printf("%s %s, your name contains %d letters.\n", pst->fname, pst->lname, pst->letters);
}
void cleanup(struct namect *pst)
{
    free(pst->fname);
    free(pst->lname);
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