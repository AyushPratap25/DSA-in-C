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
struct Node *case_c(struct Node *root, struct Node *curr, struct Node *prev);
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
        else if (curr->data < key)
            curr = curr->rchild;
    }
    if (curr == NULL)
    {
        printf("key %d not found!!\n", key);
        return root;
    }

    /* cases */
    // exacltly 2 child
    if (curr->lchild != NULL && curr->rchild != NULL)
        root = case_c(root, curr, prev);
    // exactly 1 child
    else if ((curr->lchild != NULL && curr->rchild == NULL) || (curr->lchild == NULL && curr->rchild != NULL))
        root = case_b(root, curr, prev);
    // exaclty 0 child
    else
        root = case_a(root, curr, prev);
    return root;
}

// case_a (0 child)
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

// case_b : exaclyt one child (left/right)
struct Node *case_b(struct Node *root, struct Node *curr, struct Node *prev)
{
    // del node is root
    if (prev == NULL)
    {
        struct Node *temp = NULL;
        if (curr->lchild != NULL)
        {
            temp = curr->lchild;
        }
        else if (curr->rchild != NULL)
        {
            temp = curr->rchild;
        }
        free(curr);
        return temp;
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

#pragma region Isuue code case_c
// case_c : exactly 2 child
struct Node *case_c(struct Node *root, struct Node *curr, struct Node *prev)
{

    // inorder succesor
    struct Node *temp = curr;
    struct Node *temp_prev = NULL;

    temp = temp->rchild;
    while (temp->lchild != NULL)
    {
        temp_prev = temp;
        temp = temp->lchild;
    } // temp we get the inorder succesor of curr

    // del node is root
    if (prev == NULL && temp_prev == NULL)
    {
        struct Node *child = curr->lchild;
        struct Node *temp = curr->rchild;
        temp->lchild = child;
        free(curr);
        return temp;
    }
    else if (prev == NULL && temp_prev != NULL)
    {
        temp_prev->lchild = NULL;
        temp->rchild = curr->rchild;
        temp->lchild = curr->lchild;
        return temp;
    }

    temp_prev->lchild = NULL;

    // linking temp
    temp->rchild = curr->rchild;
    temp->lchild = curr->lchild;

    if (prev->lchild == curr)
        prev->lchild = temp;

    else if (prev->rchild == curr)
        prev->rchild = temp;

    free(curr);
    return root;
}
#pragma endregion

// case_c : exactly 2 children
struct Node *case_c(struct Node *root, struct Node *curr, struct Node *prev)
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
