//
// Created by 沈洪灯 on 2022/9/4.
//

/*本文件用来测试各个基本的代码框架是否能够正常使用*/
/*
#include <iostream>
#include "QUEUE/Queue.h"

 * //test Queue
using namespace std;
int Queue(){
    Queue Q;
    initializeQueue(Q);
    int x;
    cout << "输入数据：" << endl;
    for (int i = 0; i < 5; i++){
        cin >> x;
        enQueue(Q, x);
    }
    ShowQueue(Q);
    for (int i = 0; i < 5; i++){
        deQueue(Q, x);
        cout << x << "\t";
    }
    return 0;
}*/

#include <iostream>
#include "GRAPH/graph.h"
int TestGraph(){
    Graph G;
    Initilize(G);
    Creat(G);
    ShowGraph(G);
}

//int main(){
//    TestGraph();
//}
