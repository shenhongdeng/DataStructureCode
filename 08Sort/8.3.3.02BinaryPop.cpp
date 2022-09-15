//
// Created by 沈洪灯 on 2022/9/15.
//


#include <iostream>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void BinaryPop(int arr[], int low, int high){
    /*这个里边能自动解决low和high的值的问题*/
    while (low < high){
        for (int i = low; i < high; i++)
            if (arr[i] > arr[i + 1]) swap(arr[i], arr[i + 1]);
        high --;
        for (int j = high; j > low; j--)
            if (arr[j] < arr[j - 1]) swap(arr[j], arr[j - 1]);
        low ++;
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
//    BinaryPop(arr, 0, len - 1);
//    for (int i = 0; i < len; i++)
//        cout << arr[i] << "\t";
//    cout << endl;
//}
