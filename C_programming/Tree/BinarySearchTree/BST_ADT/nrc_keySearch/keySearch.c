#include <stdio.h>
#include <stdlib.h>

// tree node structure
struct Node
{
    int data;
    struct Node *lchild;
    struct Node *rchild;
};

struct Node *keySearch(struct Node *root, int key)
{
    if (root == NULL)
        return NULL; // tree empty!

    struct Node *curr = root;

    // search
    while (curr != NULL)
    {
        if (curr->data == key) // key found
            return curr;
        if (curr->data > key)
            curr = curr->lchild;
        else
            curr = curr->rchild;
    }

    return NULL; // key not found! (curr == NULL)
}

int main()
{

    return 0;
}