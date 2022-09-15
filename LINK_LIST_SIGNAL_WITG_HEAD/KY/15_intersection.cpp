//
// Created by 沈洪灯 on 2022/8/18.
//

#include <iostream>
#include "../single_link_list_with_head.h"

void intersection(linkList &A, linkList &B){
    listNode *pa = A->link, *pb = B->link, *temp;
    A->link = nullptr;
    while(pa != nullptr and pb != nullptr){
        if (pa->data == pb->data){
            temp = pa;
            pa = pa->link;
            temp->link = A->link;
            A->link = temp;
            temp = pb;
            pb = pb->link;
            delete temp;
        }
        else if(pa->data < pb->data){
            temp = pa;
            pa = pa->link;
            delete temp;
        } else{
            temp = pb;
            pb = pb->link;
            delete temp;
        }
    }
    if (pa) pb = pa;
    while(pb){
        temp = pb;
        pb = pb->link;
        delete temp;
    }
    delete B;
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
    intersection(A, B);
    std::cout <<  "After process" << std::endl;
    output(A);
    free(A);
    return 0;
}
*/
