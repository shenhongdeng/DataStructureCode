//
// Created by 沈洪灯 on 2022/9/9.
//

#include <iostream>
#include "../TREE/Tree.h"
using namespace std;

bool FindMaxMin(BSTree T, int &max, int &min){
    if (T == nullptr)
        return false;
    BSTNode *p = T;
    while(p != nullptr){ // 找最小
        min = p->key;
        p = p->lchild;
    }
    p = T;
    while(p != nullptr){ // 找最大
        max = p->key;
        p = p->rchild;
    }
    return true;
}



/*
int main(){
    int arr[50];
    int len = 0;
    cout << "输入元素个数：";
    cin >> len;
    cout << "请输入元素" << endl;
    for (int i = 0; i < len; i++)
        cin >> arr[i];
    int key = 0;
    BSTree T = ConstructBinarySearchTree(arr, len);
    LNR(T);
    int max = T->key;
    int min = T->key;
    cout << FindMaxMin(T, max, min) << endl;
    cout << max << "\t" << min <<endl;
}
*/

