//
// Created by 沈洪灯 on 2022/9/7.
//

#include <iostream>
using namespace std;

int BinarySearch(int arr[], int low, int high, int key){
    if (low > high)
        return -1;
    int mid = (low + high) / 2;
    if (arr[mid] == key)
        return mid;
    else if(arr[mid] > key)
        return BinarySearch(arr, low, mid - 1, key);
    else
        return BinarySearch(arr, mid + 1, high, key);
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
//    cout << "输入查找的关键字：";
//    cin >>  key;
//    cout << BinarySearch(arr, 0, len - 1, key);
//}

