//
// Created by 沈洪灯 on 2022/9/6.
//

#include "Tree.h"
#include <iostream>
using namespace std;
void LNR(BSTree T){
    if (T == nullptr)
        return;
    else{
        LNR(T -> lchild);
        cout << T -> key << "\t";
        LNR(T -> rchild);
    }
}


bool BST_Create(BSTree &T, int key){
    if (T == nullptr){ // 头结点是空的
        T = new BSTNode;
        T -> lchild = T -> rchild = nullptr;
        T -> key = key;
        return true;
    }
    // 寻找插入的位置
    BSTNode *p = nullptr; // 父亲指针
    BSTNode *s = T; // 工作指针
    int left = 0; // 为0右边插入，为1左边插入
    while(s != nullptr){
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
    BSTNode *temp = new BSTNode;
    temp -> key = key;
    temp -> lchild = temp -> rchild = nullptr;
    if (left == 1)
        p -> lchild = temp;
    else
        p -> rchild = temp;
    return true;
}



BSTree ConstructBinarySearchTree(int arr[], int len){
    BSTree T;
    for (int i = 0; i < len; i++){
       BST_Create(T, arr[i]);
    }
    return T;
}


void LNRReturnOrder(BSTree T, int arr[], int &pos){ // 实现中序遍历并返回序列数组
    if (T == nullptr) return;
    LNRReturnOrder(T->lchild, arr, pos);
    arr[pos++] = T->key;
    LNRReturnOrder(T->rchild, arr, pos);
}

