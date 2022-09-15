//
// Created by 沈洪灯 on 2022/9/6.
//

#ifndef KY_TREE_H
#define KY_TREE_H
typedef struct BSTNode{
    int key;
    struct BSTNode *lchild, *rchild;
}BSTNode, *BSTree;

typedef struct BSTCountNode{
    int key;
    int count;
    struct BSTCountNode *lchild, *rchild;
}BSTCountNode, *BSTCountTree;

void LNR(BSTree);
void LNRReturnOrder(BSTree , int arr[], int &pos); // 实现中序遍历并返回遍历的数组
bool BST_Create(BSTree &T, int key);
BSTree ConstructBinarySearchTree(int arr[], int len);
BSTCountTree ConstructBinarySearchTreeWithCount(int arr[], int len);
void LNRCountTree(BSTCountTree);
#endif //KY_TREE_H
