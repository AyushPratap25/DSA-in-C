/* Iterative AVL Tree implementation with stack-based insertion */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "stack.h"
#define MAX 50

// AVL Tree Node
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
    newNode->height = 1; // here node represents the height

    return newNode;
}
// Right Rotation
struct Node *rightRotate(struct Node *y)
{
    struct Node *x = y->lchild;
    struct Node *T2 = x->rchild;
    // link nodes
    x->rchild = y;
    y->lchild = T2;

    // update heights
    y->height = 1 + max(getHeight(y->lchild), getHeight(y->rchild));
    x->height = 1 + max(getHeight(x->lchild), getHeight(x->rchild));

    return x;
}
// Left Rotation
struct Node *leftRotate(struct Node *x)
{
    struct Node *y = x->rchild;
    struct Node *T2 = y->lchild;

    x->rchild = T2;
    y->lchild = x;

    // update heights
    x->height = 1 + max(getHeight(x->lchild), getHeight(x->rchild));
    y->height = 1 + max(getHeight(y->lchild), getHeight(y->rchild));

    return y;
}

// Iterative AVL insertion
struct Node *insert(struct Node *root, int key)
{
    stack s1;
    init(&s1);
    struct Node *newNode = createNode(key);
    if (root == NULL)
        return newNode;

    struct Node *curr = root;
    struct Node *prev = NULL;

    // get the insertion point
    while (curr != NULL)
    {
        if (curr->data == key)
        {
            free(newNode);
            return root; // duplicate key, do nothing
        }
        prev = curr;
        if (curr->data > key)
        {
            push(&s1, curr);
            curr = curr->lchild;
        }
        else if (curr->data < key)
        {
            push(&s1, curr);
            curr = curr->rchild;
        }
    }
    // insert the newNode as a child of prev
    // note : newly inserted node balance_factor is always 0 since it is itself a child with no child
    if (prev->data > key)
        prev->lchild = newNode;
    else
        prev->rchild = newNode;

    // update height and rebalance along the path
    while (!isEmpty(&s1))
    {
        struct Node *node = pop(&s1);

        // height
        node->height = 1 + max(getHeight(node->lchild), getHeight(node->rchild));

        // balancef
        int balance = getBalanceFactor(node);

        // tracks rotated subtree root
        struct Node *rotated = node; // this can be kept NULL no issue but make sure to do if (!isEmpty && rotated != NULL) in "if" and (rotated != NULL) in "else if" to skip this part if no rotation happens just v1 and v2.

        #pragma region CASES
        // LL case
        if (balance > 1 && key < node->lchild->data)
        {
            rotated = rightRotate(node);
        }

        // RR case
        else if (balance < -1 && key > node->rchild->data)
        {
            rotated = leftRotate(node);
        }

        // LR case
        else if (balance > 1 && key > node->lchild->data)
        {
            node->lchild = leftRotate(node->lchild);
            rotated = rightRotate(node);
        }

        // RL case
        else if (balance < -1 && key < node->rchild->data)
        {
            node->rchild = rightRotate(node->rchild);
            rotated = leftRotate(node);
        }
        #pragma endregion

        // link rotated subtree to parent
        if (!isEmpty(&s1))
        {
            // We are not at the root → attach rotated subtree to its parent
            struct Node *parent = peak(&s1); // top of the stack
            if (parent->lchild == node)
                parent->lchild = rotated;
            else if (parent->rchild == node)
                parent->rchild = rotated;
        }
        else if (rotated != node) // stack empty
        {
            // We are at the root level
            // If rotation happened, update root to point to new subtree root.
            root = rotated;
        }
    }

    return root; // return the root node;
}

void preorderTrav(struct Node *root)
{
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preorderTrav(root->lchild);
    preorderTrav(root->rchild);
}

int isAVL(struct Node *root)
{
    if (root == NULL)
        return 1;

    int lh = getHeight(root->lchild);
    int rh = getHeight(root->rchild);

    if (abs(lh - rh) > 1)
        return 0;

    return isAVL(root->lchild) && isAVL(root->rchild);
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

    printf("\n");
    printf("%d", isAVL(root));
    return 0;
}