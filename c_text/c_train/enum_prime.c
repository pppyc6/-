/* enum_prime.c -- 使用枚举类型的值 */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
enum spectrum {red, ornage, yellow, green, blue, violet};
const char *colors[] = {"red", "orange", "yellow", "green", "blue", "violet"};
#define LEN 30
char *s_gets(char *str, int n);
int main()
{
    char    choice[LEN];
    enum    spectrum color;
    bool    color_is_found = false;

    

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
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}
