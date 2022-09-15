//
// Created by 沈洪灯 on 2022/8/18.
//

#ifndef KY_SIGNAL_CYCLE_WITH_HEAD_H
#define KY_SIGNAL_CYCLE_WITH_HEAD_H
typedef int elemType;
typedef struct node
{
    elemType data;
    struct node * link;
}listNode, *linkList, LNode, *List;

void decorate();
void intilize(linkList &first);
void create(linkList &first);//输入头指针和节点个数，创造链表
void free(linkList &first);//释放指针
bool _delete(linkList &first, elemType &x, int i);//删除指针删除后返回bool值，并带回删除的数据
bool insert(linkList &first, elemType x, int i);//插入指针插入成功之之后返回一个bool值
int length(linkList first);//函数返回链表的长度
void output(linkList first);//逐一输出链表节点的数据
linkList find(linkList first, elemType x);//查找成功返回链表所载节点的指针，查找失败返回返回空指针
void makeEmpty(linkList &first);//清空链表,这里等价于完全释放链表

#endif //KY_SIGNAL_CYCLE_WITH_HEAD_H
