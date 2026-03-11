/* 
          10
        /    \
       5      20
      / \    /  \
     3   7  15   25
    / \ / \      / \
   2  4 6  8    22 30

*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

// tree node structure
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

/* prototype */
#pragma region Prototypes
struct Node *createNode(int val);
void nrec_preorder(struct Node *root);
void freeTree(struct Node *root);
// stack
void init(stack *s);
int isEmpty(stack *s);
int isFull(stack *s);
void push(stack *s, struct Node *item);
struct Node *pop(stack *s);
#pragma endregion

// inorder traversal
void nrec_inorderTrav(struct Node *root)
{
    if (root == NULL)
        return;

    stack s;
    init(&s);

    struct Node *curr = root;

    while (curr != NULL || !isEmpty(&s))
    {
        // push all left node into stack
        while (curr != NULL)
        {
            push(&s, curr);
            curr = curr->lchild;
        }
        // pop and move right
        curr = pop(&s);
        printf("%d ", curr->data);
        curr = curr->rchild;
    }
    printf("\n");
}

int main()
{
    // Level 0
    struct Node *root = createNode(10);

    // Level 1
    root->lchild = createNode(5);
    root->rchild = createNode(20);

    // Level 2
    root->lchild->lchild = createNode(3);
    root->lchild->rchild = createNode(7);
    root->rchild->lchild = createNode(15);
    root->rchild->rchild = createNode(25);

    // Level 3
    root->lchild->lchild->lchild = createNode(2);
    root->lchild->lchild->rchild = createNode(4);
    root->lchild->rchild->lchild = createNode(6);
    root->lchild->rchild->rchild = createNode(8);
    root->rchild->rchild->lchild = createNode(22);
    root->rchild->rchild->rchild = createNode(30);

    printf("Tree created successfully!\n");

    // traversing call
    nrec_inorderTrav(root);

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

// freeTree
void freeTree(struct Node *root)
{
    if (!root)
        return;
    freeTree(root->lchild);
    freeTree(root->rchild);
    free(root);
}
