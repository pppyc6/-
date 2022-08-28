/* booksave_prime.c -- 在文件中保存结构中的内容 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXTITL 41
#define MAXAUTL 41
#define MAXBKS  10
struct book
{
    char    title[MAXTITL];
    char    author[MAXAUTL];
    float   value;
};
char *s_gets(char *str, int n);
int main()
{
    struct book library[MAXBKS];
    int     count = 1;
    int     index, filecount;
    FILE    *pbooks;
    int     size = sizeof(struct book);
    if((pbooks = fopen("book.dat", "a + b")) == NULL)
    {
        fputs("Can't open book.dat file\n", stderr);
        exit(EXIT_FAILURE);
    }
    rewind(pbooks);
    while (count < MAXBKS && fread(&library[count], size, 1, pbooks) == 1)
    {
        if(count == 0)
            puts("Current contents of book.dat:");
        printf("%s by %s %.2f\n", library[count].title, library[count].author, library[count].value);
        count++;
    }
    filecount = count;
    if (count == MAXBKS)
    {
        fputs("The book.dat file is full.", stderr);
        exit(EXIT_FAILURE);
    }
    puts("Please add new book titles.");
    puts("Please [enter] at the start of a line to stop.");
    while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL && library[count].title[0] != '\0')
    {
        puts("Now enter the arthor.");
        s_gets(library[count].author, MAXAUTL);
        puts("Now enter the value.");
        scanf("%f", &library[count].value);
        while(getchar() != '\n')
                continue;
        if(count < MAXBKS)
            puts("Enter the next title.");
    }
    if(count > 0)
    {
        puts("Here is the list of your books:");
        for(index = 0; index < count; index++)
            printf("%s by %s: $%.2f\n", library[count].title, library[count].author, library[count].value);
        fwrite(&library[filecount], size, count - filecount, pbooks);
    }
    else
        puts("No books? Too bad.");
    puts("Bye");
    fclose(pbooks);
    
    

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
        if(find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}
