/* friends_prime.c -- 使用指向结构的指针 */
#include <stdio.h>
#define LEN 21
struct names
{
    char first[LEN];
    char last[LEN];
};
struct guy
{
    struct names handle;
    char favfood[LEN];
    char job[LEN];
    float income;
};
int main()
{
    struct guy fellow[2] = {
        {
            {"Ewen", "Villard"},
            "grilled salmon",
            "personality coach",
            68112.00
        },
        {
            {"Rodney", "Swillbelly"},
            "tripe",
            "tabloid editor", 
            432400.00
        }
    };
    struct guy *him; 
    printf("address #1: %p #2: %p\n", &fellow[0], &fellow[1]);
    him = &fellow[0];
    printf("pointer #1: %p #2: %p\n", him, him + 1);

    return 0;
}
