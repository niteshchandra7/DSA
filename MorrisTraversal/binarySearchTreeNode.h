#ifndef _BINARY_SEARCH_TREENODE_H_
#define _BINARY_SEARCH_TREENODE_H_

#include<iostream>

class BinarySearchTreeNode
{
    friend std::ostream& operator<<(std::ostream& os, BinarySearchTreeNode* root);
public:
    int value;
    BinarySearchTreeNode *left;
    BinarySearchTreeNode *right;

    BinarySearchTreeNode(int value) : value(value),left(NULL), right(NULL) {}
};

#endif
