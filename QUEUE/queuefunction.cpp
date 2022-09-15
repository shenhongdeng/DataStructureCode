//
// Created by 沈洪灯 on 2020/12/1.
//
#include "Queue.h"

bool judgeEmptyQueue(const Queue &Q)
{
    return Q.front == nullptr;
}

void enQueue(Queue &Q, int x)
{
    pQueueNode pNew  = new QueueNode;
    if(pNew == nullptr)
    {
        std::cout << "Creat new node error!" << std::endl;
    } else{
        pNew -> link = nullptr;
        pNew -> value = x;
        Q.rear -> link = pNew;
        Q.rear = pNew;
    }
}
void deQueue(Queue &Q, int &x)
{
    if(judgeEmptyQueue(Q))
    {
        std::cout << "Empty link queue!" << std::endl;
        return ;
    } else{
        pQueueNode p = Q.front->link;
        x = p->value;
        if (Q.front == Q.rear) // 这个时候队列中只有一个节点，删除之后要将头和尾都指向空的
            Q.front = Q.rear = nullptr;
        else
            Q.front = Q.front->link;
        delete p;
    }
}

void initializeQueue(Queue &Q)
{

    Q.front = Q.rear = new QueueNode;
    Q.front -> link = nullptr;
}

void ShowQueue(const Queue &Q){
    std::cout << "Now the state of the Queue: ";
    pQueueNode p = Q.front->link;
    while(p){
        std::cout << p->value << "\t";
        p = p->link;
    }
    std::cout << std::endl;
}