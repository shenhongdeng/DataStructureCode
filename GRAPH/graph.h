//
// Created by 沈洪灯 on 2022/9/4.
//

#ifndef GRAPH_GRAPH_H
#define GRAPH_GRAPH_H
const int NumVertices = 100;//顶点个数
typedef char elemType;//顶点数据类型
typedef int EdgeData;//用来储存两个顶点之间的权重

//下面的这个结构体用来储存从一个节点出发，达到其他节点的信息
typedef struct Node{
    int dest;//为指向的对象
    EdgeData cost;//权重
    struct Node *link;
}Node, *pNode;


//这个节点用来储存每一个节点的信息，包括data指向的第一个节点
typedef struct VertexNode{
    elemType data;
    pNode firstAdj;
}VertexNode;

typedef struct AdjGraph{
    VertexNode G[NumVertices];
    int VerNum, EdgeNum;//n 和 e分别用来储存顶点的个数和边的个数。
}AdjGraph, Graph;

void Initilize(AdjGraph &GR);
void Free(AdjGraph &GR);
void Creat(AdjGraph &GR);
int GetFirst(const AdjGraph &GR, int v);//n表示的是第几号元素
int GetNext(const AdjGraph &GR, int v, int w);//获得后面的一个节点
void DFS(const AdjGraph &GR, int v, int *visited);
void DFSTraverse(const AdjGraph &GR);
void BFS(const AdjGraph &GR, int v, int *visited);
void BGraphTraverse(const AdjGraph &GR);
void inOut_degree(const AdjGraph &GR);
char MapIdx2Ver(AdjGraph G, int from);
int MapVer2Idx(AdjGraph G, int from);
void ShowGraph(const AdjGraph &GR);
#endif //KY_GRAPH_H
