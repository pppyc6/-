/* varargs_prime.c -- 用数量变化参量计算 */
#include <stdio.h>
#include <stdarg.h>

int main()
{


    return 0;
}
double sum(int lim, ...)
{
    va_list ap;
    double tot = 0;
    int i;

    va_start(ap, lim);
    for(i = 0; i < lim;  i ++)
        tot += va_arg(ap, double);
}