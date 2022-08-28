/* reverse_prime -- 倒序显示文件的内容 */

#include <stdio.h>
#include <stdlib.h>
#define CNTL_Z '\032' /* DOS文本文件的文件结尾标记 */
#define SLEM 81

int main(void)
{
    char file[SLEM];
    char ch;
    FILE *fp;
    long count, last;

    puts("Enter the name of the file to be processed:");
    scanf("%80s", file);
    /* 只读模式 */
    if((fp = fopen(file, "r")) == NULL)
    {
        fprintf(stderr, "reverse can`t open %s\n", file);
        exit(EXIT_FAILURE);
    }
    /* 定位到文件末尾 */
    fseek(fp, 0L, SEEK_END);
    last = ftell(fp);
    for ( count = 1L; count <= last ; count ++)
    {
        /* 回退 */
        fseek(fp, -count, SEEK_END);
        ch = getc(fp);
        /* MS-DOS文件 */
        if(ch != CNTL_Z && ch != '\r')
            putchar(ch);
    }
    putchar('\n');
    fclose(fp);

    return 0;
}