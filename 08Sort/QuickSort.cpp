//
// Created by 沈洪灯 on 2022/9/13.
//
#include <iostream>
using namespace std;

#include <time.h>

int Partition(int arr[], int low, int high){
    int pivot = arr[low];
    // 遍历整个low到high区间，使整个区间有序
    while (low < high){
        // 从右往左找打第一个小于基准的，和low进行交换，将这个元素放到基准的左边
        while (low < high and arr[high] > pivot) high--;
        arr[low] = arr[high]; // 进行交换
        // 从左边往右边找到一个大于基准的元素，将这个元素放到基准的右边
        while (low < high and arr[low] < pivot) low++;
        arr[high] = arr[low];
    }
    arr[low] = pivot;
    return low;
}

void QuickSort(int arr[], int low, int high){
    if (low < high){
        int pivot = Partition(arr, low, high);
        QuickSort(arr, low, pivot - 1);
        QuickSort(arr, pivot + 1, high);
    }
}

//int main(){
//    clock_t start_t,finish_t;
//    int arr[50];
//    int len = 0;
//    cout << "输入元素个数：";
//    cin >> len;
//    cout << "请输入元素" << endl;
//    for (int i = 0; i < len; i++)
//        cin >> arr[i];
//    for (int i = 0; i < len; i++)
//        cout << arr[i] << "\t";
//    cout << endl;
//    // 注意下边不能传入len，传入len的话会出错的
//    start_t = clock();
//    QuickSort(arr, 0, len - 1);
//    finish_t = clock();
//    for (int i = 0; i < len; i++)
//        cout << arr[i] << "\t";
//    cout << "\t" << finish_t - start_t << endl;
//    cout << endl;
//}