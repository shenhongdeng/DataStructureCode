//
// Created by 沈洪灯 on 2022/9/9.
//

//
// Created by 沈洪灯 on 2022/9/8.
//

#include <iostream>
#include "../TREE/Tree.h"
using namespace std;

int JudgeBalance(BSTree T, bool &flag){
    if (T == nullptr)
        return 0;
    int leftJHeight = JudgeBalance(T->lchild, flag);
    int rightHeight = JudgeBalance(T->rchild, flag);
    if (leftJHeight - rightHeight > 1 or leftJHeight - rightHeight < -1)
        flag = false;
    return rightHeight > leftJHeight ? rightHeight + 1 : leftJHeight + 1;
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
//    BSTree T = ConstructBinarySearchTree(arr, len);
//    LNR(T);
//    bool flag = true;
//    cout << "\n" << JudgeBalance(T, flag) << endl;
//    cout << flag << endl;
//}
//
