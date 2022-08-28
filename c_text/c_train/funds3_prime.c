/* funds3_prime.c -- 传递一个结构 */
#include <stdio.h>
#define FUNDLEN 51
struct funds
{
    char    bank[FUNDLEN];
    double  bankfund;
    char    save[FUNDLEN];
    double  savefund;
};
double sum(struct funds moolah);
int main()
{
    struct funds stan = {
        "Garlic-Melon Bank",
        4032.27,
        "Lucky's Saving and Loan",
        8543.94};
    printf("Stan has a total of $%.2f.\n", sum(stan));

    return 0;
}
double sum(struct funds moolah)
{
    return (moolah.bankfund + moolah.savefund);
}