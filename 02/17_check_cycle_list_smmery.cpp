//
// Created by 沈洪灯 on 2022/8/18.
//

#include <iostream>
#include "../LINK_LIST_DOUBLE_CYCLE_WITH_HEAD/doubleWithHead.h"

bool check_symmetry(List L){
    DNode *left = L->llink, *right = L->rlink;
    while(left != right){
        if (left->data != right->data){
            return false;
        } else {
            left = left->llink;
            right = right->rlink;
        }
    }
    return true;
}
/*

int main() {
    std::cout << "aaa";
    linkList A;
    Initilizie(A);
    Create(A);
    print(A);
    std::cout << check_symmetry(A) << std::endl;
    Free(A);
    return 0;
}
*/