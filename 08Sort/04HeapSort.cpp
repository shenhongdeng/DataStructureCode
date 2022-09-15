//
// Created by 沈洪灯 on 2022/9/13.
//
#include <iostream>
#include <time.h>
using namespace std;


void HeapAdjust(int arr[], int k, int len){
    /*调整的思路为
     * 1.检查k的左右孩子，是否比k大
     * 2.如果更大的话，将最大的孩子上升为根节点，将这个孩子和根节点进行互换
     * 3.然后查看检查是否破坏了子堆的，执行1和2*/
    int dad = k;
    // 注意这里，因为我们的下标是从零开始的，所以，起始的位置是2 * daa + 1
    for (int son = 2 * dad + 1; son < len; son = dad * 2 + 1){ // 拿到当前子堆的孩子
        if (son + 1 <= len and arr[son] < arr[son + 1]) // 判断右孩子是否存在，同时取到左右孩子中最大的
            son++;
        if (arr[son] > arr[dad]){ // 孩子大于根节点，交换，然后继续进行梳理
            int temp = arr[dad];
            arr[dad] = arr[son]; // 将孩子节点上升
            arr[son] = temp;
            dad = son; // 继续进行迭代
        } else
            return;
    }
}

void BuildHeap(int arr[], int len){
    for (int i = len / 2 - 1; i >= 0; i--)
        HeapAdjust(arr, i, len);
}

void HeapSort(int arr[], int len){
    /* 堆排序的思路如下
     * 先建立一个大根堆
     * 然后将当根堆的第一个元素（最大的元素放到arr的末尾）
     * 然后重新调整交换位置之后堆，成为一个新的堆，一直重复直到全部的元素
     * */
    BuildHeap(arr, len);
    // 这里应该是>0，因为最后一个元素更本就不用进行调整，注意这里是减减一定不是加加
    for (int i = len - 1; i > 0; i--){
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        HeapAdjust(arr, 0, i - 1);
    }
}

/*
int main(){
    clock_t start_t,finish_t;
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
    // 注意下边不能传入len，传入len的话会出错的
    BuildHeap(arr, len);
    start_t = clock();
    HeapSort(arr, len);
    finish_t = clock();
    for (int i = 0; i < len; i++)
        cout << arr[i] << "\t";
    cout << "\n" << finish_t - start_t << endl;
    cout << endl;
}
*/
