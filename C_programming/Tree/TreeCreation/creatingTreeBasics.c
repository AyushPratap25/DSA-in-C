// tree structure
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

// tree structure
struct Node
{
    int data;
    struct Node *lchild;
    struct Node *rchild;
};

// stack structure
typedef struct
{
    int top;
    struct Node *arr[MAX];
} stack;

// prototype
struct Node *createNode(int val);
void nrec_preorder(struct Node *root);
void freeTree(struct Node *root);

int main()
{
    // Level 0
    struct Node *root = createNode(50);

    // Level 1
    root->lchild = createNode(40);
    root->rchild = createNode(60);

    // Level 2
    root->lchild->lchild = createNode(30);
    root->rchild->lchild = createNode(65);
    root->rchild->rchild = createNode(70);

    // Level 3
    root->lchild->lchild->lchild = createNode(25);
    root->lchild->lchild->rchild = createNode(35);
    root->rchild->rchild->rchild = createNode(80);

    // Level 4
    root->lchild->lchild->lchild->lchild = createNode(20);
    root->lchild->lchild->rchild->lchild = createNode(33);
    root->lchild->lchild->rchild->rchild = createNode(36);

    printf("Tree created successfully!\n");

    // traversing call
    nrec_preorder(root);

    // free tree via recursion
    freeTree(root);

    return 0;
}

// node creation
struct Node *createNode(int val)
{
    struct Node *newNode = malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory Allocation failed!!\n");
        return NULL;
    }

    newNode->data = val;
    newNode->lchild = NULL;
    newNode->rchild = NULL;

    return newNode;
}

// stack
void init(stack *s)
{
    s->top = -1;
}

int isEmpty(stack *s)
{
    return (s->top == -1);
}

int isFull(stack *s)
{
    return (s->top == MAX - 1);
}

void push(stack *s, struct Node *item)
{
    if (isFull(s))
    {
        printf("Stack is Full!!\n");
        exit(0); // stop the program immediately necessary if stack limit reached while  
        // traversing, so stop the program
    }
    s->arr[++(s->top)] = item;
}

struct Node *pop(stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is Empty!!\n");
        exit(0); 
    }
    return (s->arr[(s->top)--]);
}
//

/* Tree traversal */
// preorder

void nrec_preorder(struct Node *root)
{
    if (!root)
        return;

    stack s;
    init(&s);

    struct Node *curr = root;
    push(&s, curr);

    while (!isEmpty(&s))
    {
        curr = pop(&s);
        printf("%d ", curr->data);

        if (curr->rchild != NULL)
            push(&s, curr->rchild);
        if (curr->lchild != NULL)
            push(&s, curr->lchild);
    }
    printf("\n");
}

// freeTree
void freeTree(struct Node *root)
{
    if (!root)
        return;
    freeTree(root->lchild);
    freeTree(root->rchild);
    free(root);
}
