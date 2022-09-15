//
// Created by 沈洪灯 on 2022/8/18.
//


#include <iostream>
#include "../LINK_LIST_DOUBLE_CYCLE_WITH_HEAD/doubleWithHead.h"
void Initilizie(linkList &first)
{
    first = new doubleList;
    (first) -> llink = (first) -> rlink = first;
}

void Create(linkList &first)
{
    int n = 0;
    std::cout << "Please input the number of element you input: " ;
    std::cin >> n;
    linkList p = first, q;
    int i = 1;
    while(n--)
    {
        q = new doubleList;
        std::cout << "Please input the " << i++ << "'s data ";
        std::cin >> q -> data;
        q -> rlink = first;
        q -> llink = p;
        p -> rlink = q;
        first -> llink = q;
        p = q;
    }
}

void Free(linkList &first)
{
    if(first){
        linkList p= first -> rlink, q;
        while(p != first)
        {
            q = p -> rlink;
            delete p;
            p = q;

        }
        delete first;
        std::cout << "Success free the link" << std::endl;
    }else
        std::cout << "Free the link error" << std::endl;
}

void print(linkList first)
{
    linkList p = first -> rlink;
    int i = 0;
    while(p != first)
    {
        std::cout << " -> " << p -> data;
        p = p -> rlink;
    }
    std::cout << std::endl;
}

bool Insert(linkList &first, elemType x, int n, int d) {
    linkList p = location(first, n - 1, d);
    if (p == nullptr)
        return false;
    linkList pNew = new doubleList;
    pNew->data = x;
    if (d) {
        pNew->rlink = p->rlink;
        pNew->llink = p;
        p->rlink = pNew;
        pNew->rlink->llink = pNew;
    } else {
        pNew->llink = p->llink;
        pNew->rlink = p;
        p->llink = pNew;
        pNew->llink->rlink = p;
    }
    return true;
}
linkList location(linkList first, int i, int d)
{
    if(i < 0) return nullptr;
    linkList p = first;
    int j = 0;
    while(j < i)
    {
        p = (d ? p -> rlink : p ->llink);
        j++;
        if(p == first)
            return nullptr;
    }
    return p;
}


bool _delete(linkList &first, elemType &x, int d, int i)
{
    linkList p = location(first, i, d);
    if(p == nullptr)
        return false;
    p -> rlink -> llink = p -> llink;
    p -> llink -> rlink = p -> rlink;
    x = p -> data;
    delete p;
    return true;
}

void makeEmpty(linkList first)
{
    linkList p = first -> rlink, q;
    while(p != first)
    {
        q = p -> rlink;
        delete p;
        p = q;
    }
    first -> rlink = first -> llink = first;
    std::cout << "Make empty success" << std::endl;
}

bool find(linkList first, elemType x)
{
    linkList p = first -> rlink;
    while(p != first && p -> data != x)
        p =  p -> rlink;
    if(p == first)
        return false;
    else
        return true;

}

int length(linkList first)
{
    int i = 0;
    linkList p = first -> rlink;
    for(i = 0; p != first; i++)
    {
        p = p -> rlink;
    }
    return  i;
}