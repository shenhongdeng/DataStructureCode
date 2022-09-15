//
// Created by 沈洪灯 on 2022/9/9.
//
#include <iostream>
#include "Tree.h"
using namespace std;

bool BSTInsertWithCount(BSTCountTree &T, int key){
    if (T == nullptr){ // 头结点是空的
        T = new BSTCountNode;
        T -> lchild = T -> rchild = nullptr;
        T -> key = key;
        T -> count = 1;
        return true;
    }
    // 寻找插入的位置
    BSTCountNode *p = nullptr; // 父亲指针
    BSTCountNode *s = T; // 工作指针
    int left = 0; // 为0右边插入，为1左边插入
    while(s != nullptr){
        s -> count ++;
        if (s -> key == key)
            return false;
        p = s;
        if (s -> key < key){
            s = s -> rchild;

            left = 0;
        } else {
            s = s -> lchild;
            left = 1;
        }
    }
    // 开始创建新的节点
    BSTCountNode *temp = new BSTCountNode;
    temp -> key = key;
    temp -> lchild = temp -> rchild = nullptr;
    temp -> count = 1;
    if (left == 1)
        p -> lchild = temp;
    else
        p -> rchild = temp;
    return true;
}

BSTCountTree ConstructBinarySearchTreeWithCount(int arr[], int len){
    BSTCountTree T;
    for (int i = 0; i < len; i++){
        BSTInsertWithCount(T, arr[i]);
    }
    return T;
}


void LNRCountTree(BSTCountTree T){
    if (T == nullptr)
        return;
    else{
        LNRCountTree(T -> lchild);
        cout << T -> key << "(" << T->count << ")" << "\t" ;
        LNRCountTree(T -> rchild);
    }
}