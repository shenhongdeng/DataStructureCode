//
// Created by 沈洪灯 on 2022/8/17.
//

//
// Created by 沈洪灯 on 2022/8/17.
//

#include <iostream>
#include "../single_link_list_with_head.h"

void merge_reverse(linkList &A, linkList &B){
    listNode *p, *tempA = A->link, *tempB = B->link;
    A->link = nullptr;
    B->link = nullptr;
    while(tempA and tempB){
        if (tempA->data < tempB->data){
             p = tempA;
             tempA = tempA->link;
             p->link = A->link;
             A->link = p;
             std::cout << "ha";
        } else{
            p = tempB;
            tempB = tempB -> link;
            p->link = A->link;
            A->link = p;
        }
    }
    if(tempA) tempB = tempA;
    while(tempB){
        p = tempB;
        tempB = tempB -> link;
        p->link = A->link;
        A->link = p;
    }
    delete(B);
    output(A);
}


//int main(){
//    linkList A = new listNode;
//    linkList B = new listNode;
//    std::cout << "Create A" << std::endl;
//    create(A);
//    output(A);
//    std::cout << "Create B" << std::endl;
//    create(B);
//    output(B);
//    merge_reverse(A, B);
//    return 0;
//}
