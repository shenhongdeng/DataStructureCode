//
// Created by 沈洪灯 on 2022/9/15.
//

/* 找到数组中的第K小的数字
 * 简单的思路可以用快排然后直接选取第k小的数字
 * 这样的时间复杂度为O(nlogn)，不是很理想
 * 其实可以参考上学期算法课上学的寻找第K大算法
 * 用堆排序的话时间复杂度是O(n+klog2n)，前边的n是建立小跟堆的时间，然后klogn是进行k次进行调整的算法
 * 可以用快排的思路
 * 在一趟划分中，
 * 如果k正好等于基准所在的位置（low），那么可以直接返回
 * 如果k > 划分的基准，就在数组的上半部分
 * 如果k < 划分的基准，在数组的下半部分
 * */

#include <iostream>
using namespace std;

int FindKth(int arr[], int low, int high, int k){
    int pivot = arr[low];
    int old_low = low, old_high = high;
    while (low < high){
        while (low < high and arr[high] > pivot) high--;
        arr[low] = arr[high];
        while (low < high and arr[low] < pivot) low++;
        arr[high] = arr[low];
    }
    arr[low] = pivot;
    if (low == k)
        return pivot;
    else if (k > pivot)
        return FindKth(arr, low + 1, old_high, k);
    else
        return FindKth(arr, old_low, low - 1, k);
}
//int main(){
//    int arr[50];
//    int len = 0;
//    cout << "输入元素个数：";
//    cin >> len;
//    cout << "请输入元素" << endl;
//    for (int i = 0; i < len; i++)
//        cin >> arr[i];
//    cout << FindKth(arr, 0, len - 1, 3) << endl;
//    for (int i = 0; i < len; i++)
//        cout << arr[i] << "\t";
//    cout << endl;
//}
