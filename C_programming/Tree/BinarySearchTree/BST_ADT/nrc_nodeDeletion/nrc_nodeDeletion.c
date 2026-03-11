/* write the code get the mistake learn it correct it and go ahead */
// Diagrams, visualisation...
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *lchild;
    struct Node *rchild;
};

// prototype
#pragma region Prototype
struct Node *delTreeNode(struct Node *root, int key);
struct Node *case_a(struct Node *root, struct Node *curr, struct Node *prev);
struct Node *case_b(struct Node *root, struct Node *curr, struct Node *prev);
struct Node *case_c(struct Node *root, struct Node *curr);
#pragma endregion

struct Node *delTreeNode(struct Node *root, int key)
{
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
    // exactly 2 child
    if (curr->lchild != NULL && curr->rchild != NULL)
        root = case_c(root, curr);
    // exactly 1 child
    else if ((curr->lchild != NULL || curr->rchild != NULL))
        root = case_b(root, curr, prev);
    // exactly 0 child
    else
        root = case_a(root, curr, prev);

    return root;
}

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
struct Node *case_c(struct Node *root, struct Node *curr)
{
    struct Node *succ = curr->rchild;
    struct Node *succ_prev = curr;
    // inorder successor
    while (succ->lchild != NULL)
    {
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



// pointer way more error prone 
struct Node *case1_c(struct Node *root, struct Node *curr, struct Node *prev)
{
    // Step 1: Find inorder successor (leftmost node in right subtree)
    struct Node *succ = curr->rchild; // successor
    struct Node *succ_prev = curr;    // parent of successor
    
    while (succ->lchild != NULL)
    {
        succ_prev = succ;
        succ = succ->lchild;
    }
    
    // Step 2: Detach successor from its original position
    if (succ_prev != curr) // successor is not immediate right child
    {
        succ_prev->lchild = succ->rchild; // attach successor's right child to its parent
        succ->rchild = curr->rchild;      // move curr's right subtree to successor
    }
    // If successor is immediate right child, its right subtree is already correct
    
    succ->lchild = curr->lchild; // attach curr's left subtree to successor
    
    // Step 3: Attach successor to parent of curr
    if (prev == NULL) // deleting root
    {
        free(curr);
        return succ; // new root
    }
    
    if (prev->lchild == curr)
    prev->lchild = succ;
    else
    prev->rchild = succ;
    
    free(curr);
    return root;
}