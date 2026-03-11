/* write the code get the mistake learn it correct it and go ahead */
// Diagrams, visualisation...
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

// AVL Tree Node 
struct Node
{
    int data;
    struct Node *lchild;
    struct Node *rchild;
    int height;
};

// AVL_Balancing_Utility_Functions 
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


// AVL_Node_Deletion_Utility_Funciton 
// case_a exactly 0 child
struct Node *case_a(struct Node *root, struct Node *curr, struct Node *prev)
{
    // del node is root
    if (prev == NULL)
    {
        free(curr);
        return NULL;
    }
    //
    if (prev->lchild == curr)
        prev->lchild = NULL;
    else if (prev->rchild == curr)
        prev->rchild = NULL;

    free(curr);
    return root;
}

// case_b : exactly one child (left/right)
struct Node *case_b(struct Node *root, struct Node *curr, struct Node *prev)
{
    // del node is root
    if (prev == NULL)
    {
        struct Node *newRoot = NULL;
        if (curr->lchild != NULL)
        {
            newRoot = curr->lchild;
        }
        else if (curr->rchild != NULL)
        {
            newRoot = curr->rchild;
        }
        free(curr);
        return newRoot;
    }
    //
    struct Node *child = NULL;
    if (curr->lchild != NULL)
        child = curr->lchild;
    else if (curr->rchild != NULL)
        child = curr->rchild;

    if (prev->lchild == curr)
        prev->lchild = child;
    else if (prev->rchild == curr)
        prev->rchild = child;

    free(curr);
    return root;
}

// case_c : exactly 2 children (data-copying method)
struct Node *case_c(struct Node *root, struct Node *curr, stack *s1)
{
    struct Node *succ = curr->rchild;
    struct Node *succ_prev = curr;

    // (Remember we just copied the data, that means the node address remians the same)
    push(&s1, curr); // simple yet intelligent (yet now holds old data, but once data copied it holds the new one)
    // inorder successor
    while (succ->lchild != NULL)
    {
        push(&s1, succ);
        succ_prev = succ;
        succ = succ->lchild;
    }

    // data-copying
    curr->data = succ->data;

    // node deletion
    if (succ->lchild == NULL && succ->rchild == NULL)
        root = case_a(root, succ, succ_prev);
    else 
        root = case_b(root, succ, succ_prev);

    return root;
}
// handle the stack part for case_c imp.


/* AVL_Node_Del_Main */
struct Node *delAVLTreeNode(struct Node *root, int key)
{
    stack s1;
    init(&s1);

    if (root == NULL)
    {
        printf("Tree is empty!!\n");
        return NULL;
    }

    // searching key
    struct Node *curr = root;
    struct Node *prev = NULL;
    while (curr != NULL)
    {
        if (curr->data == key)
            break;
        push(&s1, curr);
        prev = curr;
        if (curr->data > key)
            curr = curr->lchild;
        else 
            curr = curr->rchild;
    }
    if (curr == NULL)
    {
        printf("key %d not found!!\n", key);
        return root;
    }

    /* Cases */
    #pragma region Node_Deletion_Cases
    // exactly 2 child
    if (curr->lchild != NULL && curr->rchild != NULL)
        root = case_c(root, curr, &s1);
    // exactly 1 child
    else if ((curr->lchild != NULL || curr->rchild != NULL))
        root = case_b(root, curr, prev);
    // exactly 0 child
    else
        root = case_a(root, curr, prev);
    #pragma endregion
    
    // update height and rebalance along the path
    while (!isEmpty(&s1))
    {
        struct Node *node = pop(&s1);

        // height
        node->height = 1 + max(getHeight(node->lchild), getHeight(node->rchild));

        // balancef
        int balance = getBalanceFactor(node);

        // tracks rotated subtree root
        struct Node *rotated = node;

        #pragma region CASES
        // LL case
        if (balance > 1 && getBalanceFactor(node->lchild) >= 0)
        {
            rotated = rightRotate(node);
        }

        // RR case
        else if (balance < -1 && getBalanceFactor(node->rchild) <= 0)
        {
            rotated = leftRotate(node);
        }

        // LR case
        else if (balance > 1 && getBalanceFactor(node->lchild) < 0)
        {
            node->lchild = leftRotate(node->lchild);
            rotated = rightRotate(node);
        }

        // RL case
        else if (balance < -1 && getBalanceFactor(node->rchild) > 0)
        {
            node->rchild = rightRotate(node->rchild);
            rotated = leftRotate(node);
        }
        #pragma endregion

        // link rotated subtree to parent
        if (!isEmpty(&s1))
        {
            struct Node *parent = peek(&s1); // top of the stack
            if (parent->lchild == node)
                parent->lchild = rotated;
            else if (parent->rchild == node)
                parent->rchild = rotated;
        }
        else if (rotated != node) // stack empty
        {
            root = rotated;
        }
    }
    return root;
}
