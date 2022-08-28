/* lianbiao_pyc.c -- 第一个链表 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PSIZE 41
char *s_gets(char *st, int n);
struct lianbiao
{
    char someting[PSIZE];
    struct lianbiao *next;
};

int main()
{
    struct lianbiao *head = NULL;
    struct lianbiao *prev, *current;
    char some[PSIZE];

    while(s_gets(some, PSIZE) != NULL && some[0] != '\0')
    {
        current = (struct lianbiao *)malloc(sizeof(struct lianbiao));
        if(head == NULL)
            head = current;
        else
            prev->next = current;
        current->next = NULL;
        strcpy(current->someting, some);
        prev = current;
    }
    // 展示
    current = head;
    while(current != NULL)
    {
        printf("%s", current->next);
        current = current->next;
    }
    // 释放内存
    while(current != NULL)
    {
        
    }

    return 0;
}
char *s_gets(char *st, int n)
{
    char *ret_val;
    char *find;
    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}