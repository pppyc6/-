#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
// // 初始化
// void InitiallizeQueue(Queue *pq);

// // 检查队列是否已经满
// bool QueueIsFull(const Queue *pq);

// // 检查队列是否为空
// bool QueueIsEmpty(const Queue *pq);

// // 在末尾添加项
// bool EnQueue(Item item, Queue *pq);

// // 从末尾开始删除项
// bool DeQueue(Item *pitem, Queue *pq);

// // 清空队列
// void EmptyTheQueue(Queue *pq);
void InitiallizeQueue(Queue * pq)
{
    pq->front = pq->rear = NULL;
    pq->items = 0;
}
bool QueueIsFull(const Queue *pq)
{
    return pq->items == MAXQUEQUE;
}
bool QueueIsEmpty(const Queue * pq)
{
    return pq->items == 0;
}
int QueueItemcCount(const Queue * pq)
{
    return pq->items;
}
bool EnQueue(Item item, Queue * pq)
{
    Node * pnew;

    if(QueueIsFull(pq))
        return false;
    pnew = (Node *) malloc(sizeof(Node));
    if(pnew == NULL)
    {
        fprintf(stderr, "Unable to allocate memory!\n");
        exit(1);
    }
    pnew->
}