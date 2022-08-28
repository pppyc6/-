/* flexmemb_prime.c -- 伸缩型数组成员(C99新增特性) */
#include <stdio.h>
#include <stdlib.h>

struct flex
{
    size_t count;
    double average;
    double scores[];
};

void showFlex(const struct *pst);
int main()
{   
    struct flex *pf1, *pf2;
    int n = 5;
    int i;
    int tot = 0;

    pf1 = malloc(sizeof(struct flex) + n * sizeof(double));
    pf1->count = n;
    for ( i = 0; i < n; i++)
    {
        pf1->scores[i] = 20.0 - i;
        tot += pf1->scores[i];
    }
    

    return 0;
}
void showFlex(const struct *pst)
{
    int i;
    printf("Scores:");
    for(i = 0; i < pst->count; i++)
        printf("%g", p->scores[i]);
    printf("\nAverage:%g\n", p->average);
}