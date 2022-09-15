/*
//
// Created by 沈洪灯 on 2022/9/14.
//

#include <iostream>
using namespace std;
int n = 50;

int *B = (int *)malloc((n + 1) * sizeof(int));  // 辅助数组用来临时进行存储
void Merge(int A[], int low, int mid, int high){
    int i, j, k; // i，j分别用来在在临时数组中指向两个数组当前操作到的位置，k用来指向原数组中，现在合并到了什么位置
    for (int a = low; a <= high; a++)
        B[a] = A[a]; // 将两个合并的数组拷贝到辅助数组中
    for (i = low, j = mid + 1, k = low; i <= mid and j <= high; k++){
        if (B[i] <= B[j]) // 带等号是为了保证稳定
            A[k] = B[i++];
        else
            A[k] = B[j++];
    }
    while (i <= mid)  A[k++] = B[i++];  // 直接将没有放入的进行放入
    while (j <= high) A[k++] = B[j++];
}


void MergeSort(int A[], int low, int high){
    if (low <  high){              // 直到只有一个元素为止
        int mid = (low + high) / 2;      // 从中间划分
        MergeSort(A, low, mid);      // 对左边的半部分进行归并排序
        MergeSort(A, mid + 1, high); // 对右边的部分进行归并排序
        Merge(A, low, mid, high);    // 合并
    }
}

int main(){
    int arr[50];
    int len = 0;
    cout << "输入元素个数：";
    cin >> len;
    cout << "请输入元素" << endl;
    for (int i = 0; i < len; i++)
        cin >> arr[i];
    MergeSort(arr, 0, len - 1);
    for (int i = 0; i < len; i++)
        cout << arr[i] << "\t";
    cout << endl;
}
*/
