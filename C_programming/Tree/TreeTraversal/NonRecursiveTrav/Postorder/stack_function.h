#include <stdio.h>
#include <stdlib.h>
#define MAX 5

// stack struct
typedef struct 
{
    int top;
    struct Node *arr[MAX];
} stack;

// prototype 
#pragma region Prototype
void init(stack *s);
int isEmpty(stack *s);
int isFull(stack *s);
void push(stack *s, struct Node *item);
struct Node* pop(stack *s);
#pragma endregion

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
        printf("Stack size limit reached!!\n");
        return;
    }
    s->arr[++(s->top)] = item;
}

struct Node* pop(stack *s)
{
    if (isEmpty(s)) 
    {
        printf("stack empty !!\n");
        return NULL;
    }
    return (s->arr[(s->top)--]);
}
