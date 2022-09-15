//
// Created by 沈洪灯 on 2020/11/30.
//

#ifndef GRAPH_SEQUENCE_H
#define GRAPH_SEQUENCE_H

//#include "Graphs.h"
#include <iostream>
typedef struct QueueNode{
    int value;
    struct  QueueNode *link;
}QueueNode, *pQueueNode;

typedef struct Queue
{
    pQueueNode front;
    pQueueNode rear;
}Queue;

void initializeQueue(Queue &Q);
void enQueue(Queue &Q, int v);
void deQueue(Queue &Q, int &w);
bool judgeEmptyQueue(const Queue &Q);
void ShowQueue(const Queue &Q);
#endif //GRAPH_SEQUENCE_H
