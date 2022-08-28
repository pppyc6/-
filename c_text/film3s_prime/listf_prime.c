/* listf_prime.c -- 接口函数定义 */
#include <stdio.h>
#include <stdlib.h>
#include "list_prime.h"
/* 局部函数原型 */
static void CopyToNode(Item item, Node *pnode);
/* 接口函数 */
/* 把链表设置为空 */
void InitializeList(List *plist)
{
    *plist = NULL;
}
/* 如果链表为空，返回true */
bool ListIsEmpty(const List *plist)
{
    if(*plist == NULL)
        return true;
    else
        return false;
}
/* 如果链表为满，返回true */
bool ListIsFull(const List *plist)
{
    Node *pt;
    bool full;
    pt = (Node *)malloc(sizeof(Node));
    if(pt == NULL)
        full = true;
    else
        full = false;
    free(pt);
    return full;
}
/* 返回节点的数量 */
unsigned int ListItemCount(const List *plist)
{
    unsigned int count = 0;
    Node *pnode = *plist;
    while(pnode != NULL)
    {
        ++count;
        pnode = pnode->next;
    }
    return count;
}
/* 创建储存项的节点，并将其添加至由plist指向的链表末尾(较慢的实现) */
bool AddItem(Item item, List *plist)
{
    Node *pnew;
    Node *scan = *plist;
    
    pnew = (Node *) malloc(sizeof(Node));
    if(pnew == NULL)
        return false; // 失败时退出函数

    CopyToNode(item, pnew);
    pnew->next = NULL;
    if(scan == NULL)
        *plist = pnew;
    else
    {
        while(scan->next != NULL)
            scan = scan->next;
        scan = pnew;
    }
    return true;
}
/* 访问每个节点并执行pfun指向的函数 */
void Traverse(const List *plist, void (*pfun)(Item item))
{
    Node *pnode = *plist;
    while(pnode != NULL)
    {
        (*pfun) (pnode->item); // 把函数应用于链表中的项
        pnode = pnode->next; // 前进到下一项
    }
}
/* 释放由malloc()分配的内存，设置链表指针为NULL */
void EmptyTheList(List *plist)
{
    Node *psave;

    while(*plist != NULL)
    {
        psave = (*plist)->next;
        free(*plist);
        *plist = psave;
    }
}

/* 局部函数定义 */
static void CopyToNode(Item item, Node *pnode)
{
    pnode->item =item;
}