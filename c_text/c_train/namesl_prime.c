/* namesl.c -- 使用结构的指针 */
#include <stdio.h>
#include <string.h>

#define NLEN 30
struct namect
{
    char    fname[NLEN];
    char    lname[NLEN];
    int     letters;
};
int getinfo(struct namect *pst);
void makeinfo(struct namect *pst);
void showinfo(const struct namect *pst);
char *s_gets(char *str, int n);
int main()
{     
    struct namect person;

    while(getinfo(&person) == 0)
    {
        makeinfo(&person);
        showinfo(&person);
    }
    return 0;
}
int getinfo(struct namect *pst)
{
    char *f, *l;
    printf("Please enter your first name.\n");
    f = s_gets(pst->fname, NLEN);
    printf("Please enter your last name.\n");
    l = s_gets(pst->lname, NLEN);
    if(*f != '\0' && *l != '\0')
        return 0;
    else
        return -1;
}
void makeinfo(struct namect *pst)
{
    pst->letters = strlen(pst->fname) + strlen(pst->lname);
}
void showinfo(const struct namect *pst)
{
    printf("%s %s, your name contains %d letters.\n", pst->fname, pst->lname, pst->letters);
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