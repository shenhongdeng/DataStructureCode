////
//// Created by 沈洪灯 on 2022/9/7.
////
//#include <iostream>
//using namespace std;
//
//int SwapFound(int arr[], int len, int key){
//    int i = 0;
//    for (i = 0; i < len and arr[i] != key; i++);
//    if (i >= len)
//        return -1;
//    if (i != 0){
//        int temp = arr[i];
//        arr[i] = arr[i - 1];
//        arr[i - 1] = temp;
//    }
//    return i;
//}
//
//
//
//int main(){
//    int arr[50];
//    int len = 0;
//    cout << "输入元素个数：";
//    cin >> len;
//    if (len <= 0) return 0;
//    cout << "请输入元素" << endl;
//    for (int i = 0; i < len; i++)
//        cin >> arr[i];
//    int key = 0;
//    for (int i = 0; i < len; i++)
//        cout << arr[i] << "\t";
//    cout << endl;
//    cout << "输入查找的关键字：";
//    cin >>  key;
//    cout << SwapFound(arr, len, key) << endl;
//    for (int i = 0; i < len; i++)
//        cout << arr[i] << "\t";
//}
//
