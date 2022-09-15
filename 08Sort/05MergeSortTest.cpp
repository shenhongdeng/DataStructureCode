//
// Created by 沈洪灯 on 2022/9/14.
//

#include <iostream>
using namespace std;
int n = 50;
int B[50];

void Merge(int arr[], int low, int mid, int high){
    int i, j, k;
    for (int a = low; a <= high; a++)
        B[a] = arr[a]; // 拷贝到辅助数组中
    for (k = low, i = low, j = mid + 1; i <= mid and j <= high; k++){
        if (B[i] <= B[j]) // 保证稳定性
            arr[k] = B[i++];
        else
            arr[k] = B[j++];
    }
    while (i <= mid) arr[k++] = B[i++];
    while (j <= high) arr[k++] = B[j++];
}

void MergeSort(int arr[], int low, int high){
    if (low < high){
        int mid = (low + high) / 2;
        MergeSort(arr, low, mid);
        MergeSort(arr, mid + 1, high);
        Merge(arr, low, mid, high);
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
//    MergeSort(arr, 0, len - 1);
//    for (int i = 0; i < len; i++)
//        cout << arr[i] << "\t";
//    cout << endl;
//}
