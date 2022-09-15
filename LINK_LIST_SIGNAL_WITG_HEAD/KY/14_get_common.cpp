//
// Created by 沈洪灯 on 2022/8/18.
//

#include <iostream>
#include "../single_link_list_with_head.h"

linkList get_common(linkList &A, linkList &B){
    listNode *pa = A->link, *pb = B->link, *temp;
    linkList C = new listNode;
    C->link = nullptr;
    while(pa != nullptr and pb != nullptr){
        if (pa->data == pb->data){
            temp = new listNode;
            temp->data = pa->data;
            temp->link = C->link;
            C->link = temp;
            pa = pa->link;
            pb = pb->link;
        } else if (pa->data < pb->data){
            pa = pa->link;
        } else {
            pb = pb->link;
        }
    }
    output(C);
    return C;
}



/*
int main(){
    linkList A = new listNode;
    linkList B = new listNode;
    linkList C;
    std::cout << "Create A" << std::endl;
    create(A);
    output(A);
    std::cout << "Create B" << std::endl;
    create(B);
    output(B);
    C = get_common(A, B);
    std::cout << "Output C" << std::endl;
    output(C);
    free(A);
    free(B);
    free(C);
    return 0;
}
*/
