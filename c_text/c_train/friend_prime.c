/* friend_prime -- 嵌套结构示例 */
#include <stdio.h>
#define LEN 21
const char *msgs[5] =
{
    "   Thank you for the wonderful evening, ",
    "You certainly prove that a",
    "is a special kind of guy. We must get togethe", 
    "Over  a delicious",
    " and have a few laughs"
};
// 第1个结构
struct names
{
    char first[LEN];
    char last[LEN];
};
// 第2个结构
struct guy
{
    struct names handle;
    char favfood[LEN];
    char job[LEN];
    float income;
};
int main(void)
{
    struct guy fellow = {
        {"Ewen", "Villard"},
        "grilled salmon",
        "personality coach",
        68112.00
    };
    printf("Dear %s, \n\n", fellow.handle.first);
    printf("%s%s.\n", msgs[0], fellow.handle.first);
    printf("%s%s\n", msgs[1], fellow.job);
    printf("%s\n", msgs[2]);
    printf("%s%s%s", msgs[3], fellow.favfood, msgs[4]);
    if (fellow.income > 150000.0)
        puts("!!");
    else if(fellow.income > 75000.0)
        puts("!");
    else
        puts(".");
    printf("\n%40s%s\n", " ", "See you soon,");
    printf("%40s%40s\n", " ", "Shalala");

    return 0;
}
