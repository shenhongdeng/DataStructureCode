//
// Created by 沈洪灯 on 2022/8/18.
//

#ifndef KY_DOUBLEWITHHEAD_H
#define KY_DOUBLEWITHHEAD_H
typedef int elemType;
typedef struct doubleLink{
    elemType data;
    doubleLink *rlink, *llink;
}doubleList, *List, DNode;
typedef doubleList* linkList;
int length(linkList first);
void Initilizie(linkList &first);
void Create(linkList &first);
void Free(linkList &first);
void print(linkList first);
linkList location(linkList first, int i, int d);
bool Insert(linkList &first, elemType x, int n, int d);
bool _delete(linkList &first, elemType &x, int d, int i);
void makeEmpty(linkList first);
bool find(linkList first, elemType x);
#endif //KY_DOUBLEWITHHEAD_H
