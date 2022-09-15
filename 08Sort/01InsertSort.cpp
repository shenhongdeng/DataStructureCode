//
// Created by 沈洪灯 on 2022/9/13.
//
#include <iostream>
using namespace std;
/*[1, 2, 3, 4, 2]*/
void InsertSort(int arr[], int len){
    int i, j = 0;
    for (i = 1; i < len; i++){
        int temp = arr[i];
        for (j = i - 1; j >= 0 and arr[j] > temp; j --)
            arr[j + 1] = arr[j];
        arr[j + 1] = temp; //
    }
}

void InsertSortBinarySearch(int arr[], int len){
    /*用折半查找，查找前边的插入位置*/
    int i = 0, j = 0, low, high, mid;
    for (i = 1; i < len; i++){
        int temp = arr[i];
        low = 0;
        high = i - 1;
        while (low <= high){
            mid = (low + high) / 2;
            if (arr[mid] <= temp)
                low = mid + 1;
            else
                high = mid - 1;
        }
        for (j = i - 1; j >= low; j--)
            arr[j + 1] = arr[j];
        arr[low] = temp;
    }
}


void ShellSort(int arr[], int len){
    /*
     * 相当于从指定间隔中选取元素构成一个新的小的数组，然后对小的数组进行插入排序，使小的数组内部变得有序
     * 然后不断的缩小间隔，直到间隔为1为止*/
    int d, i, j;
    for (int d = len / 2; d >= 1; d = d / 2){
        // 轮流处理每一个划分的组，这是实现的是轮流在不同的字表进行处理
        for (i = d; i < len; i++){ //相当于进行了d个插入排序，每一个插入排序使数组内部变得有序
            int temp = arr[i];
            for (j = i - d; j >= 0 and arr[j] > temp; j -= d)
                arr[j + d] = arr[j];
            arr[j + d] = temp;
        }
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
//    for (int i = 0; i < len; i++)
//        cout << arr[i] << "\t";
//    cout << endl;
////    InsertSort(arr, len);
//    InsertSortBinarySearch(arr, len);
//    for (int i = 0; i < len; i++)
//        cout << arr[i] << "\t";
//    cout << endl;
//}