/* Function to check if Tree is AVL */
/* Order of trav dosent matter, what matters is every node is traversed and checked for AVL property */
#include <stdio.h>
#define MAX 30

struct Node
{
    int data;
    struct Node *lchild;
    struct Node *rchild;
    int height;
};

#pragma region Stack
typedef struct
{
    int top;
    struct Node *arr[MAX];
} stack;

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
        return;
    }
    s->arr[++(s->top)] = item;
}

struct Node *pop(stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty!!\n");
        return NULL;
    }
    return (s->arr[(s->top)--]);
}

struct Node *peak(stack *s)
{
    if (isEmpty(s))
        return NULL; // error code
    return (s->arr[s->top]);
}

#pragma endregion

int getHeight(struct Node *n) {
    if (n == NULL) return 0;
    return (n->height);
} int getBalanceFactor(struct Node *n) {
    if (n == NULL) return 0;
    return (getHeight(n->lchild) - getHeight(n->rchild));
}

int isAVL(struct Node *root)
{
    if (root == NULL)
        return 1;

    stack s1;
    init(&s1);

    push(&s1, root);
    struct Node *curr = root;

    while (!isEmpty(&s1))
    {
        struct Node *node = pop(&s1);
        int balance = getBalanceFactor(node);
        if (balance > 1 || balance < -1)
            return 0; // Unbalanced node, Tree not avl
        if (node->rchild != NULL)
            push(&s1, node->rchild);
        if (node->lchild != NULL)
            push(&s1, node->lchild);
    }
    return 1;
}

