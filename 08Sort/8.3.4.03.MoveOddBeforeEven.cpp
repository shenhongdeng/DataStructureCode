////
//// Created by 沈洪灯 on 2022/9/15.
////
//#include <iostream>
//using namespace std;
//
//
//void swap(int &a, int &b){
//    int temp = a;
//    a = b;
//    b = temp;
//}
///*
// * 实现的思路如下
// * 运用快排选取基准进行划分的思路
// * 当数组的low和high没有相遇的时候，一直保持循环，知道low和high相遇
// * 从low开始往右边寻找，找到第一个偶数
// * 从high开始向左边寻找，找到第一个奇数
// * 将找到的奇数和偶数进行位置互换
//*/
//
//void MoveOddBeforeEven(int arr[], int low, int high){
//    while (low < high){
//        while (low < high and arr[low] % 2 != 0) low++;
//        while (low < high and arr[high] % 2 != 1) high--;
//        swap(arr[low], arr[high]);
//        low ++; high --; // 把这个元素跳过一定不能少
//    }
//}
//
//
////int main(){
////    int arr[50];
////    int len = 0;
////    cout << "输入元素个数：";
////    cin >> len;
////    cout << "请输入元素" << endl;
////    for (int i = 0; i < len; i++)
////        cin >> arr[i];
////    MoveOddBeforeEven(arr, 0, len - 1);
////    for (int i = 0; i < len; i++)
////        cout << arr[i] << "\t";
////    cout << endl;
////}
