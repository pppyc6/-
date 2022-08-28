/* invert4_prime.c -- 使用位操作显示二进制 */
#include <stdio.h>
#include <limits.h>
char *itobs(int n, char *ps);
void show_bstr(const char *str);
int invert_end(int num, int bits);

int main()
{
    char    bin_str[CHAR_BIT * sizeof(int) + 1];
    int     number;
    while (scanf("%d", &number) == 1)
    {
        itobs(number, bin_str);
        printf("%d is \n", number);
        show_bstr(bin_str);
        putchar('\n');
        number = invert_end(number, 4);
        printf("Inverting the last 4 bits gives\n");
        itobs(number, bin_str);
        show_bstr(bin_str);
        putchar('\n');
    }

    return 0;
}
char *itobs(int n, char *ps)
{
    int     i;
    static const int size = CHAR_BIT * sizeof(int);
    for (i = size - 1; i >= 0; i--, n >>= 1)
        ps[i] = (01 & n) + '0';
    ps[size] = '\0';

    return ps;
}
void show_bstr(const char *str)
{
    int     i = 0;
    while (str[i])
    {
        putchar(str[i]);
        if (++i % 4 == 0 && str[i])
            putchar(' ');
    }
}
int invert_end(int num, int bits)
{
    int     mask = 0;
    int     bitval = 1;
    while (bits-- > 0)
    {
        mask |= bitval;
        bitval <<= 1;
    }
    return (num ^ mask);
}