/* Binary search via recursion an easy one */
#include <stdio.h>

struct Node
{
    int data;
    struct Node *lchild;
    struct Node *rchild;
};

struct Node *search(struct Node *root, int key)
{
    if (root == NULL)
        return NULL;       // tree empty
    if (root->data == key) // return node for which key found
        return root;
    else if (root->data > key)
        return (search(root->lchild, key)); // move to left node
    else
        return (search(root->rchild, key)); // move to right node
}

int main()
{
    return 0;
}