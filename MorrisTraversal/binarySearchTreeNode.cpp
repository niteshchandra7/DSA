#include "binarySearchTreeNode.h"

std::ostream &operator<<(std::ostream &os, BinarySearchTreeNode *root)
{
    BinarySearchTreeNode *curr = root;
    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            os << curr->value << "\t";
            curr = curr->right;
        }
        else
        {
            BinarySearchTreeNode *temp = curr->left;
            while (temp->right != NULL && temp->right != curr)
            {
                temp = temp->right;
            }
            if (temp->right == NULL)
            {
                temp->right = curr;
                curr = curr->left;
            }
            else
            {
                temp->right = NULL;
                os << curr->value << "\t";
                curr = curr->right;
            }
        }
    }
    return os;
}
