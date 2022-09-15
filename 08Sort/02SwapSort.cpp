//
// Created by 沈洪灯 on 2022/9/13.
//
#include <iostream>
using namespace std;

/*[5, 4, 3, 2, 1]*/
void BubbleSort(int arr[], int n){
    bool flag;
    // 执行了n次
    for (int i = 0; i < n - 1; i++){
        flag = true;
        // 从最后边一个往前边冒
        for (int j = n - 1; j > i; j--){
            // 注意上边结束的条件
            if (arr[j - 1] > arr[j]){
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
                flag = false;
            }
        }
        // 如果没有发生换位的话，直接结束
        if (flag == true)
            break;
    }
}




/*
int main(){
    int arr[50];
    int len = 0;
    cout << "输入元素个数：";
    cin >> len;
    cout << "请输入元素" << endl;
    for (int i = 0; i < len; i++)
        cin >> arr[i];
    for (int i = 0; i < len; i++)
        cout << arr[i] << "\t";
    cout << endl;
    BubbleSort(arr, len);
    for (int i = 0; i < len; i++)
        cout << arr[i] << "\t";
    cout << endl;
}*/
