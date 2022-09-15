//
// Created by 沈洪灯 on 2022/9/8.
//

#include <iostream>
#include "../TREE/Tree.h"
using namespace std;

bool JudgeBinarySortTree(BSTree T, int len){
    int *LNROrder = new int[len];
    int pos = 0;
    LNRReturnOrder(T, LNROrder, pos);
    for (int i = 0; i < len; i++){
        cout << LNROrder[i] << "\t";
    }
    cout << endl;
    for (int i = 1; i < len; i++){
        if (LNROrder[i] < LNROrder[i - 1])
            return false;
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
   cout << JudgeBinarySortTree(T, len) << endl;
}*/
