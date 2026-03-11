#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *lchild;
    struct Node *rchild;
    int height;
};

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int getHeight(struct Node *n)
{
    if (n == NULL)
        return 0;
    return (n->height);
}

int getBalanceFactor(struct Node *n)
{
    if (n == NULL)
        return 0;
    return (getHeight(n->lchild) - getHeight(n->rchild));
}

struct Node *createNode(int key)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
        return NULL; // memory allocation failed!!

    newNode->data = key;
    newNode->lchild = NULL;
    newNode->rchild = NULL;
    newNode->height = 1;

    return newNode;
}

struct Node *rightRotate(struct Node *y)
{
    struct Node *x = y->lchild;
    struct Node *T2 = x->rchild;

    x->rchild = y;
    y->lchild = T2;

    y->height = 1 + max(getHeight(y->lchild), getHeight(y->rchild));
    x->height = 1 + max(getHeight(x->lchild), getHeight(x->rchild));

    return x;
}

struct Node *leftRotate(struct Node *x)
{
    struct Node *y = x->rchild;
    struct Node *T2 = y->lchild;

    x->rchild = T2;
    y->lchild = x;

    x->height = 1 + max(getHeight(x->lchild), getHeight(x->rchild));
    y->height = 1 + max(getHeight(y->lchild), getHeight(y->rchild));

    return y;
}

struct Node *insert(struct Node *node, int key)
{
    if (node == NULL)
        return createNode(key);

    if (node->data > key)
        node->lchild = insert(node->lchild, key);
    else if (node->data < key)
        node->rchild = insert(node->rchild, key);
    else
        return node; // duplicate key
    // update height of each node
    node->height = 1 + max(getHeight(node->lchild), getHeight(node->rchild));

    int balancef = getBalanceFactor(node);

    // Left Left case
    if (balancef > 1 && key < node->lchild->data)
        return rightRotate(node);
    // Right Right case
    else if (balancef < -1 && key > node->rchild->data)
        return leftRotate(node);

    // Left Right case
    else if (balancef > 1 && key > node->lchild->data)
    {
        node->lchild = leftRotate(node->lchild);
        return rightRotate(node);
    }
    // Right Left case
    else if (balancef < -1 && key < node->rchild->data)
    {
        node->rchild = rightRotate(node->rchild);
        return leftRotate(node);
    }
    
    return node; // return the root node;
}

void preorderTrav(struct Node *root)
{
    if (root == NULL)
        return;
    
    printf("%d ", root->data);
    preorderTrav(root->lchild);
    preorderTrav(root->rchild);
}

int main()
{
    struct Node *root = NULL;
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 4);
    root = insert(root, 8);
    root = insert(root, 2);
   
    preorderTrav(root);
    return 0;
}