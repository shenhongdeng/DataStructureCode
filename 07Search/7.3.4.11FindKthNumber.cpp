//
// Created by 沈洪灯 on 2022/9/9.
//

#include <iostream>
#include "../TREE/Tree.h"
using namespace std;

BSTCountNode *FindKth(BSTCountTree T, int k){
    if (k < 1 or k > T->count) return nullptr;

    if (T->lchild == nullptr){
        if (k == 1)
            return T;
        else
            return FindKth(T->rchild, k - 1);
    }
    else{
        if (T->lchild->count == k - 1) return T;
        if (T->lchild->count < k - 1)
            return FindKth(T->rchild, k - (T->lchild->count + 1));
        else
            return FindKth(T->lchild, k);
    }

}



//int main(){
//    int arr[50];
//    int len = 0;
//    cout << "输入元素个数：";
//    cin >> len;
//    cout << "请输入元素" << endl;
//    for (int i = 0; i < len; i++)
//        cin >> arr[i];
//    int key = 0;
//    cout << "输入关键字：";
//    cin >> key;
//    BSTCountTree T = ConstructBinarySearchTreeWithCount(arr, len);
//    LNRCountTree(T);
//    cout << endl;
//    cout << FindKth(T, key)->key << endl;
//}
