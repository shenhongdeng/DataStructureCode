//
// Created by 沈洪灯 on 2020/9/28.
//


#include <iostream>
#include "single_Link_list_with_head.h"
using namespace std;
void intilize(LinkList &first)
{
    first -> link= nullptr;
}

void create(LinkList &first)
{
    int n;
    std::cout << "Please input the number of link list" << std::endl;
    std::cin >> n;

    LinkList pNew;
    for (int i = 1; i <= n; i++)
    {
        pNew = new LinkNode;
        std::cout << "Please input the " << n + 1 - i << "'s data ";
        std::cin >> pNew -> data;
        pNew -> link = first -> link;
        first -> link = pNew;
    }
}

void CreateInsertInTail(LinkList &first){
    cout << "建立正向链表，尾插" << endl;
    cout << "元素个数: ";
    int n;
    cin >> n;
    if(n <= 0) return;
    LinkNode *p = first, *tail = first, *temp;
    cout << "输入元素：" << endl;
    for (int i = 0; i < n; i++){
        temp = new LinkNode;
        cin >> temp->data;
        temp->link = tail->link;
        tail->link = temp;
        tail = temp;
    }
}

void free(LinkList &first)
{
    LinkList p;
    while (first != nullptr)
    {
        p = first;
        first = p -> link;
        delete p;
    }
    std::cout << "Success free the link list" << std::endl;
}

void output(LinkList first)
{
    LinkList p = first -> link;
    int i = 1;
    while (p != nullptr)
    {
        std::cout << " -> " << p->data;
        p = p->link;
    }
    std::cout << std::endl;
}

int length(LinkList first)
{
    int i = 0;
    LinkList p = first -> link;
    while(p != nullptr)
    {
        p = p -> link;
        i++;
    }
    return i;
}

bool insert(LinkList &first, elemType x, int i)
{
    if(i < 1) return false;
    LinkList p = first;//指向插入节点的前一个；
    int a = 0;
    while(p != nullptr && a < i - 1)
    {
        p = p ->link;
        a++;
    }
    if(p == nullptr && first != nullptr)
    {
        return false;
    }
    LinkList pNew = new LinkNode;
    pNew -> data = x;
    pNew -> link = p -> link;
    p -> link = pNew;
    return true;
}

bool _delete(LinkList &first, elemType &x, int i)
{
    LinkList temp,p = first;
    int a = 0;
    if(i <= 0)
        return false;
    while(p != nullptr && a < i - 1)
    {
        a++;
        p = p -> link;
    }
    if(p == nullptr || p -> link == nullptr)
        return false;
    temp = p -> link;
    p -> link = temp -> link;
    x = temp -> data;
    delete temp;
    return true;
}
LinkList find(LinkList first, elemType x){
    LinkList p = first -> link;
    while(p != nullptr && p -> data != x)
        p = p -> link;
    if(p == nullptr)
        return nullptr;
    else
        return p;
}
void makeEmpty(LinkList &first)
{
    LinkList p;
    while(first -> link != nullptr)
    {
        p = first -> link;
        first -> link = p -> link;
        delete p;
    }
    first -> link = nullptr;
    std::cout << "Suceess make the list link empty" << std::endl;
}

void decorate()
{
    std::cout << "<=======================================================>"<< std::endl;
}