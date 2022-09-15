//
// Created by 沈洪灯 on 2022/9/9.
//

#include <iostream>
#include "../TREE/Tree.h"
using namespace std;

/*
 * 如果直接遍历整个树输出的话，能实现要求，但是时间复杂度和空间复杂度都和遍历整个树的开销是一样的
 * 但是这种一定能实现
 * 所以考虑更加优优秀的算法，结合排序二叉树的性质来进行实现
 *
 * 题目看错了，是按照从大到小的顺序输出不小于k的关键字
 * 我们只需要先遍历右子树，然后遍历根节点，然后遍历左子树，这样就能得到从大到小的顺序，
 * */
void ShowLessThanKey(BSTree T, int key){
    if (T == nullptr)
        return;
    ShowLessThanKey(T->rchild, key);
    if (T->key >= key)
        cout << T->key << "\t";
    ShowLessThanKey(T->lchild, key);

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
//    BSTree T = ConstructBinarySearchTree(arr, len);
//    LNR(T);
//    cout << endl;
//    ShowLessThanKey(T, key);
//}

