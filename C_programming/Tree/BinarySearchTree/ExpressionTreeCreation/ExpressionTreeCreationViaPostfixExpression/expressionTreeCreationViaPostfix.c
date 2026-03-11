/* Expression tree via postfix */
// make sure to free the tree at the end
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 20

struct Node
{
    char data; // char
    struct Node *lchild;
    struct Node *rchild;
};
void postorder(struct Node *root)
{
    if (root == NULL)
        return;

    postorder(root->lchild);   // left
    postorder(root->rchild);   // right
    printf("%c ", root->data); // root
}

// prototype
struct Node *createExpTreePostfix(char arr[]);

int main()
{
    struct Node *root = NULL;
    char arr[] = "abc*-def/+/";

    root = createExpTreePostfix(arr);
    postorder(root);

    return 0;
}

#pragma region Stack
// stack structure
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
        printf("\nStack is full!!\n");
        return;
    }
    else
    {
        s->arr[++(s->top)] = item;
    }
}

struct Node *pop(stack *s)
{
    if (isEmpty(s))
    {
        printf("\nStack is Empty!!");
        return NULL; // fail
    }
    else
        return (s->arr[(s->top)--]);
}
#pragma endregion

struct Node *createNode(char item)
{
    struct Node *newNode = malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        return NULL;
    }
    newNode->lchild = NULL;
    newNode->rchild = NULL;
    newNode->data = item;
    return newNode;
}

struct Node *createExpTreePostfix(char arr[])
{
    stack s1;
    init(&s1);

    int n = strlen(arr); // len of the char arr[]

    for (int i = 0; i < n; i++)
    {
        struct Node *newNode = createNode(arr[i]);
        // alphabet or num
        if (isalnum(arr[i]))
        {
            push(&s1, newNode);
        }
        // operator
        else
        {
            struct Node *right = pop(&s1);
            struct Node *left = pop(&s1);
            // if invalid expression input
            if (!left || !right)
            {
                printf("Invalid postfix expression!!\n");
                return NULL;
            }
            newNode->lchild = left;
            newNode->rchild = right;
            push(&s1, newNode);
        }
    }
    return (pop(&s1)); 
}

// makes sure to free the list;