/* complit_prime.c -- 复合字面量 */
#include <stdio.h>
#define MAXTITL 41
#define MAXAUTL 31

struct book
{
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};
int main()
{
    struct book redfirst;
    int score;

    puts("Enter your score:");
    scanf("%d", &score);

    if(score >= 84)
        redfirst = (struct book) {
            "Crime and Punishment",
            "Fyodor Dostoyevsky",
            11.25
        };
    

    return 0;
}