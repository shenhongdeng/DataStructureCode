//
// Created by 沈洪灯 on 2022/8/18.
//

#include <iostream>
#include "../single_link_list_with_head.h"

bool sub_str(linkList &A, linkList &B){
    listNode *pa = A->link, *pb = B->link, *pre = A->link; // pre指向前驱
    while(pa and pb){
        if (pa->data == pb->data){
            pa = pa->link;
            pb = pb->link;
        } else {
            pre = pre->link; // pre向前移动一步
            pa = pre; // 从上次开始比较的下一个节点开始比较
            pb = B->link;
        }
    }
    if (pb == nullptr){
        return true;
    } else{
        return false;
    }
}


/*
int main(){
    linkList A = new listNode;
    linkList B = new listNode;
    std::cout << "Create A" << std::endl;
    create(A);
    output(A);
    std::cout << "Create B" << std::endl;
    create(B);
    output(B);
    std::cout << sub_str(A, B) << std::endl;
    free(A);
    free(B);
    return 0;
}
*/