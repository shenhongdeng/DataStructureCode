//
// Created by 沈洪灯 on 2022/9/6.
//
#include <iostream>
using namespace std;

#include "../TREE/Tree.h"

//typedef struct BSTNode{
//    int key;
//    struct BSTNode *lchild, *rchild;
//}BSTNode, *BSTree;



// 上边的代码是又问题的，下边是目前认为正确定的实现方式，插入的时候需要找到父节点
//bool BST_Create(BSTree &T, int key){
//    if (T == nullptr){ // 头结点是空的
//        T = new BSTNode;
//        T -> lchild = T -> rchild = nullptr;
//        T -> key = key;
//        return true;
//    }
//    // 寻找插入的位置
//    BSTNode *p = nullptr; // 父亲指针
//    BSTNode *s = T; // 工作指针
//    int left = 0; // 为0右边插入，为1左边插入
//    while(s != nullptr){
//        if (s -> key == key)
//            return false;
//        p = s;
//        if (s -> key < key){
//            s = s -> rchild;
//            left = 0;
//        } else {
//            s = s -> lchild;
//            left = 1;
//        }
//    }
//    // 开始创建新的节点
//    BSTNode *temp = new BSTNode;
//    temp -> key = key;
//    temp -> lchild = temp -> rchild = nullptr;
//    if (left == 1)
//        p -> lchild = temp;
//    else
//        p -> rchild = temp;
//    return true;
//}


/*
int main(){
    int arr[50];
    int len = 0;
    cout << "输入元素个数：";
    cin >> len;
    cout << "请输入元素" << endl;
    for (int i = 0; i < len; i++)
        cin >> arr[i];
    BSTree T = nullptr;
    for (int i = 0; i < len; i++)
        BST_Create(T, arr[i]);
    LNR(T);
}*/
