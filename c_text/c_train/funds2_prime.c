/* funds_prime.c -- 传递指向函数的指针 */
#include <stdio.h>
#define FUNDLEN 51
struct funds
{
    char bank[FUNDLEN];
    double bankfund;
    char save[FUNDLEN];
    double savefund;
};
double sum(const struct funds *money);
int main()
{
    struct funds stan = {
        "Garlic-Melon Bank",
        4032.27,
        "Lucky's Saving and Loan",
        8543.94
    };
    printf("Stan has a total of $%.2f.\n", sum(&stan));

    return 0;
}
double sum(const struct funds *money)
{
    return (money->bankfund + money->savefund);
}