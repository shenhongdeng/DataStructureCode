//
// Created by 沈洪灯 on 2022/8/18.
//

#include <iostream>
#include "../LINK_LIST_SIGNAL_CYCLE_WITH_HEAD/signal_cycle_with_head.h"

bool delete_min(List L){
    LNode *pmin = L->link, *premin = L, *p = L->link, *pre=L;
    while(L->link != L){
        pmin = L->link;
        p = L->link;
        premin = L;
        while(p != L){
            if (p->data < pmin->data){
                premin = pre;
                pmin = p;
                pre = p;
                p = p->link;
            } else {
                pre = p;
                p = p->link;
            }
        }
        premin->link = pmin->link;
        std::cout << pmin->data << std::endl;
        delete pmin;
    }
    delete L;
}

//int main() {
//    std::cout << "here";
//    linkList A;
//    intilize(A);
//    create(A);
//    output(A);
//    std::cout << delete_min(A) << std::endl;
////    output(A);
////    free(A);
//    return 0;
//}
