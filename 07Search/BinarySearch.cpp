//
// Created by 沈洪灯 on 2022/9/5.
//

#include <iostream>
typedef int ElemType;
using namespace std;

typedef struct{
    ElemType *elem;
    int TableLen;
} SSTable;

int BinarySearch(int arr[], int len, int key){
    int low = 0;
    int height = len - 1; // high指向最后一个的位置
    int mid;
    // 从下边的表格中验证之后，决定不应该加上等号
    // 因为等于的时候中间加上等号之后刚好在等于的地方是没有办法被检查到的
    while (low < height){
        mid = (low + height) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            height  = mid - 1;
    }
    return -1;
}

//int main(){
//   int arr[50];
//   int len = 0;
//   cout << "输入元素个数：";
//   cin >> len;
//   cout << "请输入元素" << endl;
//   for (int i = 0; i < len; i++)
//       cin >> arr[i];
//   int key = 0;
//   cout << "输入查询的元素: ";
//   cin >> key;
//   cout << BinarySearch(arr, len, key) << endl;
//}