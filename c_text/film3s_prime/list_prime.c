/* list_prime.c -- 使用抽象数据类型(ADT)风格的链表 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list_prime.h"

void showmovies(Item Item);
char *s_gets(char *st, int n);
void eatline(void);

int main()
{
    List movies;
    Item temp;
    // 初始化
    InitializeList(&movies);
    if(ListIsFull(&movies))
    {
        fprintf(stderr, "No memory available! Bye!\n");
        exit(EXIT_FAILURE);
    }
    // 获取用户输入并储存
    puts("Enter first movie title:");
    while(s_gets(temp.title, TSIZE) != NULL && temp.title[0] != '\0')
    {
        puts("Enter your rating <0-10>:");
        scanf("%d", &temp.rating);
        eatline();
        if(AddItem(temp, &movies) == false)
        {
            fprintf(stderr, "Problem allocating memory\n");
            break;
        }
        if(ListIsFull(&movies))
        {
            puts("The list is now full.");
            break;
        }
        puts("Enter next movie title(empty line to stop):");
    }
    /* 显示 */
    if(ListIsEmpty(&movies))
        printf("No data entered.");
    else
    {
        printf("Here is the movie list:\n");
        Traverse(&movies, showmovies);
    }
    printf("You entered %d movies.\n", ListItemCount(&movies));
    // 清理
    EmptyTheList(&movies);
    puts("Bye!");

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
void showmovies(Item item)
{
    printf("Movie %s Rating: %d\n", item.title, item.rating);
}
void eatline(void)
{
    while(getchar() != '\n')
        continue;
}