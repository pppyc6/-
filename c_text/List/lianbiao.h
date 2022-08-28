/* 这是链表函数的声明的头文，用于实现接口 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


#define NSIZE 41

typedef struct
{
    char title[NSIZE];
    int raiiting;
}Item;
typedef struct node
{
    Item film;
    struct node *next;
}Node;


/*  操作:       初始化链表
    前置条件:   创建了个指向链表的指针
    后置条件:   该指针指向NULL  */
void FirstNode(Node *pst)
{
    pst = NULL;
}
/*  操作:       检查链表是否满了？
    后置条件:   满了返回true
                不满返回false   */
bool FullIsNode(void)
{
    Node *pst;
    if((pst = (Node *) malloc(sizeof(Node))) == NULL)
    {
        fprintf(stderr, "该链表已经满了");
        exit(1);
    }
    else
        puts("该链表未满");
}
/*  前置条件:   确定使用了FullIsNode函数，不然会产生危险
    操作:       在一串链表末尾添加一个链表，没有则创立一个
    后置条件:   成功返回true，失败返回false */
void AddNode(Item item, Node *const head)
{
    Node * pnew;
    Node * scan;

    scan = head;
    pnew = (Node *) malloc(sizeof(Node));
    pnew->film = item;
    while(scan != NULL)
        scan = scan->next;
    scan = pnew;
    pnew->next = NULL;
}
/*  操作:       释放先前给与的内存
    后置条件:   成功返回true，失败返回false */
bool FreeNode(Node *pst)
{
    Node *prev;

    while(pst != NULL)
    {
        prev = pst->next;
        free(pst);
        pst = prev;
    }       
}
