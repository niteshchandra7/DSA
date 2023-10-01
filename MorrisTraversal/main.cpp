#include <iostream>
#include "binarySearchTreeNode.h"
using namespace std;

BinarySearchTreeNode* InsertInBST(BinarySearchTreeNode *root, int value)
{
    if (!root)
    {
        root = new BinarySearchTreeNode(value);
        return root;
    }
    if (root->value >= value)
    {
        root->left = InsertInBST(root->left, value);
    }
    else
    {
        root->right = InsertInBST(root->right, value);
    }
    return root;
}

int main()
{
    BinarySearchTreeNode *root = NULL;
    root = InsertInBST(root, 12);
    root = InsertInBST(root, 16);
    root = InsertInBST(root, 17);
    root = InsertInBST(root, 19);
    root = InsertInBST(root, 21);
    root = InsertInBST(root, 15);
    root = InsertInBST(root, 14);
    root = InsertInBST(root, 13);
    cout << root;
    return 0;
}
