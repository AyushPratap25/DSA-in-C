#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *lchild;
    struct Node *rchild;
};

struct Node *insert(struct Node *root, int ikey);

int main()
{
    struct Node *root = NULL;
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 12);
    root = insert(root, 25);

    printf("\n");
    return 0;
}

struct Node *insert(struct Node *root, int ikey)
{
    struct Node *newNode = malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed !!\n");
        return root;
    }
    newNode->data = ikey;
    newNode->lchild = NULL;
    newNode->rchild = NULL;

    if (root == NULL)
    {
        return newNode;
    }

    struct Node *curr = root;
    struct Node *lastNode = NULL;
    while (curr != NULL)
    {
        lastNode = curr;
        if (curr->data > ikey)
        {
            curr = curr->lchild;
        }
        else if (curr->data < ikey)
        {
            curr = curr->rchild;
        }
        else
        {
            printf("Duplicate key !!\n");
            free(newNode); // newNode allocation need to be freed, avoid meory leak
            return root;
        }
    }

    if (lastNode->data > ikey)
        lastNode->lchild = newNode;
    else if (lastNode->data < ikey)
        lastNode->rchild = newNode;

    return root;
}