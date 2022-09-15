/*
#include <iostream>
#include "../single_Link_list_with_head.h"
int main()
{
    linkList first = new listNode;

    intilize(first);

    create(first);
    decorate();
    output(first);
    decorate();
    std::cout << "The length of the link List is " << length(first) << std::endl;
    decorate();

    int place;
    elemType x;
    std::cout << "Please input the insert place ";
    std::cin >> place;
    std::cout << "Please input the element data ";
    std::cin >> x;
    if(insert(first, x, place)){
        std::cout << "Insert succeed, now the link list is" << std::endl;
        output(first);
    }else{
        std::cout << "Insert wrong" << std::endl;
    }

    decorate();
    elemType y;
    int j = 0;
    std::cout << "Please input the place you want to delete ";
    std::cin >> j;
    if(_delete(first, y, j)){
        std::cout << "Delete success the deleted element is: " << y << std::endl;
        decorate();
        std::cout << "Now the link list is:" << std::endl;
        output(first);
    }else{
        std::cout << "Delete error" << std::endl;
    }

    decorate();
    elemType findData;
    std::cout << "Please input the element you want to find ";
    std::cin >> findData;
    if(find(first, findData) == nullptr)
        std::cout << "Not find" << std::endl;
    else
        std::cout << "Success find" << std::endl;

    decorate();
    std::cout << "Now the link list is:" << std::endl;
    output(first);
    decorate();
    makeEmpty(first);
    decorate();
    free(first);
    decorate();
    return 0;
}
*/
