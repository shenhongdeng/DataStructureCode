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


void SwapColor(int arr[], int len){
    int low = 0, high = len - 1, i = 0;
    while (i <= high){
        switch (arr[i]){
            case 1:
                swap(arr[i], arr[low]);
                low++;
                i++;
                break;
            case 2:
                i++;
                break;
            case 3: // 这里不能进行i++，因为换过来的元素需要再次进行判断
                swap(arr[i], arr[high]);
                high--;
                break;
            default:
                cout << "Error!" << endl;
        }
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
    SwapColor(arr, len);
    for (int i = 0; i < len; i++)
        cout << arr[i] << "\t";
    cout << endl;
}
