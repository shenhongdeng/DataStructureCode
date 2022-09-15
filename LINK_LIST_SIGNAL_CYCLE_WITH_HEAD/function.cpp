//
// Created by 沈洪灯 on 2022/8/18.
//

#include <iostream>
#include "signal_cycle_with_head.h"
void intilize(linkList &first)
{
    first = new LNode;
    first->link = first;
    std::cout << first << " " << first->link << std::endl;
}

void create(linkList &first)
{
    int n;
    std::cout << "Please input the number of link list" << std::endl;
    std::cin >> n;

    linkList pNew;
    for (int i = 1; i <= n; i++)
    {
        pNew = new listNode;
        std::cout << "Please input the " << n + 1 - i << "'s data ";
        std::cin >> pNew -> data;
        pNew->link = first->link;
        first->link = pNew;
    }
}

void free(linkList &first)
{
    // 这个first不能直接释放
    LNode *p = first->link;
    LNode *temp = first;
    temp->link = nullptr; // 断链
    while (p != first)
    {
        temp = p;
        p  = p -> link;
        delete temp;
    }
    delete first;
    std::cout << "Success free the link list" << std::endl;
}

void output(linkList first)
{
    linkList p = first->link;
    while (p != first)
    {
        std::cout << " -> " << p->data;
        p = p->link;
    }
    std::cout << std::endl;
}

int length(linkList first)
{
    int i = 0;
    linkList p = first -> link;
    while(p != first)
    {
        p = p -> link;
        i++;
    }
    return i;
}

bool insert(linkList &first, elemType x, int i)
{
    if(i < 1) return false;
    linkList p = first;//指向插入节点的前一个；
    int a = 0;
    while(p != first && a < i - 1)
    {
        p = p ->link;
        a++;
    }
    if(p == first && first != nullptr)
    {
        return false;
    }
    linkList pNew = new listNode;
    pNew -> data = x;
    pNew -> link = p -> link;
    p -> link = pNew;
    return true;
}

bool _delete(linkList &first, elemType &x, int i)
{
    linkList temp,p = first;
    int a = 0;
    if(i <= 0)
        return false;
    while(p != first && a < i - 1)
    {
        a++;
        p = p -> link;
    }
    if(p == first || p -> link == nullptr)
        return false;
    temp = p -> link;
    p -> link = temp -> link;
    x = temp -> data;
    delete temp;
    return true;
}
linkList find(linkList first, elemType x){
    linkList p = first -> link;
    while(p != first && p -> data != x)
        p = p -> link;
    if(p == first)
        return nullptr;
    else
        return p;
}
void makeEmpty(linkList &first)
{
    linkList p;
    while(first -> link != first)
    {
        p = first -> link;
        first -> link = p -> link;
        delete p;
    }
    std::cout << "Suceess make the list link empty" << std::endl;
}

void decorate() {
    std::cout << "<=======================================================>" << std::endl;
}