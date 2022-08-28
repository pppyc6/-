/* fundsl_prime.c -- 把结构成员作为参数传递 */
#include <stdio.h>
double sum(double x, double y);
#define FUNDLEN 50

struct funds
{
    char    bank[FUNDLEN];
    double  bankfund;
    char    save[FUNDLEN];
    double  savefund;
};
int main()
{
    struct funds stan = {
        "Garlic-Melon Bank",
        4032.27,
        "Lucky's Saving and Loan",
        8543.94
    };
    printf("Stan has a total of $%.2f.\n", sum(stan.bankfund, stan.savefund));

    return 0;
}
double sum(double x, double y)
{
    return(x + y);
}