//
// Created by 沈洪灯 on 2022/9/15.
//
#include <iostream>
using namespace std;

void Move


int main(){
    int arr[50];
    int len = 0;
    cout << "输入元素个数：";
    cin >> len;
    cout << "请输入元素" << endl;
    for (int i = 0; i < len; i++)
        cin >> arr[i];
    BinaryPop(arr, 0, len - 1);
    for (int i = 0; i < len; i++)
        cout << arr[i] << "\t";
    cout << endl;
}