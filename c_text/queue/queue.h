/* queue.h -- Queue的接口 */
#ifndef _QUEUE_H_
#define _QUEUE_H_
#include <stdbool.h>
#define MAXQUEQUE 10

typedef struct item
{
    int gumption;
    int charisma;
}Item;

typedef struct node
{
    Item item;
    struct node *next;
}Node;

typedef struct queue
{
    Node *front;
    Node *rear;
    int items;
}Queue;

// 初始化
void InitiallizeQueue(Queue * pq);

// 检查队列是否已经满
bool QueueIsFull(const Queue * pq);

// 检查队列是否为空
bool QueueIsEmpty(const Queue * pq);

// 在末尾添加项
bool EnQueue(Item item, Queue * pq);

// 从末尾开始删除项
bool DeQueue(Item *pitem, Queue * pq);

// 清空队列
void EmptyTheQueue(Queue * pq);

#endif