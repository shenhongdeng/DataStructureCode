//
// Created by 沈洪灯 on 2022/9/4.
//

#include <iostream>
#include "graph.h"
#include "../QUEUE/Queue.h"
using namespace std;
//#include "Queue.h"
void Initilize(AdjGraph &GR)
{
    
    cout << "Input num Vertex:";
    cin >> GR.VerNum;
    cout << endl;
    cout << "Input Edge num";
    cin >> GR.EdgeNum;
    std::cout << "Successfully initialize!" << std::endl;
}

void Free(AdjGraph &GR)
{
    pNode p;//p是工作指针
    for(int i = 0; i < GR.VerNum; i++)
    {
        p = GR.G[i].firstAdj;
        while(GR.G[i].firstAdj != nullptr)
        {
            p = GR.G[i].firstAdj;
            GR.G[i].firstAdj = p -> link;
            delete p;
        }
        std::cout << "Free " << i << " success!" << std::endl;
    }
}


void Creat(AdjGraph &GR)
{
    for(int i = 0; i < GR.VerNum; i++)
    {
        std::cout << "Please input the " << i << "'s data: ";
        std::cin >> GR.G[i].data;
        GR.G[i].firstAdj = nullptr;
    }

    int head = 0, tail = 0, weight = 0;
    for(int j = 0; j < GR.EdgeNum; j++)
    {
        std::cout << "Please insert the "<< j + 1 << " edge's head, tail and wight, divided with space:";
        std::cin >> tail >> head >> weight;
        pNode temp = new Node;
        temp->cost = weight;
        temp->link = GR.G[tail].firstAdj;
        temp->dest = head;
        GR.G[tail].firstAdj = temp;
    }
}


int GetFirst(const AdjGraph &GR, int v)//n表示的是第几号元素
{
    if(GR.G[v].firstAdj != nullptr)
        return GR.G[v].firstAdj -> dest;//如果第一个存在空的话返回他指向的元素，否则返回-1.
    else
        return -1;
}

int GetNext(const AdjGraph &GR, int v, int w)//获得后面的一个节点
{
    pNode temp = GR.G[v].firstAdj;
    while(temp != nullptr and temp->dest != w)
    {
        temp = temp -> link;
    }
    if(temp != nullptr and temp -> link != nullptr)
        return temp->link->dest;
    else
        return -1;
}


void DFS(const AdjGraph &GR, int v, int *visited)
{
    std::cout << GR.G[v].data <<"\t";
    visited[v] = 1;
    int w = GetFirst(GR, v);
    while(w != -1)
    {
        if(visited[w] != 1)
            DFS(GR, w, visited);
        w = GetNext(GR, v, w);
    }
}


void DFSTraverse(const AdjGraph &GR)
{
    int visited[GR.VerNum];
    for(int i = 0; i < GR.VerNum; i++)
    {
        visited[i] = 0;
    }
    std::cout << "The depth first search is: " << std::endl;
    for(int i = 0; i < GR.VerNum; i++)
    {
        if(visited[i] != 1)
            DFS(GR, i, &visited[0]);
    }
    std::cout << std::endl;
}

void ShowGraph(const AdjGraph &GR)
{
    pNode p;//p是工作指针
    for(int i = 0; i < GR.VerNum; i++)
    {
        p = GR.G[i].firstAdj;
        while(p != nullptr)
        {
            std::cout << i << "->" << p->dest << "\t";
            p = p->link;
        }
        std::cout << std::endl;
    }
}

void BFS(const AdjGraph &GR, int v, int *visited, Queue &Q)
{
    std::cout << GR.G[v].data << "\t";
    visited[v] = 1;
    enQueue(Q, v);
    while(!judgeEmptyQueue(Q))
    {
        deQueue(Q,v);
        int w = GetFirst(GR, v);
        while(w != -1)
        {
            if(w == 0)
            {
                std::cout << GR.G[w].data << "\t";
                visited[w] = 1;
                enQueue(Q, w);
            }
            w = GetNext(GR, v, w);
        }
    }
}


void BGraphTraverse(const AdjGraph &GR)
{
    Queue Q;
    initializeQueue(Q);
    int visited[GR.VerNum];
    for(int i = 0; i < GR.VerNum; i++)
    {
        visited[i] = 0;
    }
    std::cout << "The bored first search is: " << std::endl;
    for(int i = 0; i < GR.VerNum; i++)
    {
        if(visited[i] != 1)
            BFS(GR, i, &visited[0], Q);
    }
    std::cout << std::endl;
}

void inOut_degree(const AdjGraph &GR)
{
    int outDegree[GR.VerNum];
    int inDegree[GR.VerNum];
    for(int i = 0; i < GR.VerNum; i++)
    {
        outDegree[i] = inDegree[i] = 0;
    }
    for(int i = 0; i  < GR.VerNum; i++)
    {
        pNode temp = GR.G[i].firstAdj;
        while(temp != nullptr)
        {
            outDegree[i]++;
            inDegree[temp->dest]++;
            temp = temp -> link;
        }
    }
    for(int j = 0; j < GR.VerNum; j++)
    {
        std::cout << "The out_degree of " << GR.G[j].data << " is: " <<  outDegree[j] << std::endl;
    }
    for(int i = 0; i < GR.VerNum; i++)
    {
        std::cout << "The in_degree of " << GR.G[i].data << " is: " << inDegree[i] << std::endl;
    }
}


char MapIdx2Ver(AdjGraph G, int from){
    return G.G[from].data;
}

int MapVer2Idx(AdjGraph G, char from){
    for (int i = 0; i < G.VerNum; i++){
        if (G.G[i].data == from)
            return i;
    }
}