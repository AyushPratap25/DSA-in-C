#include <stdio.h>
#include <stdlib.h>
#define MAX 50
/* Note this is not the way it is done this works for only one .c file but leaving it here as an experience as the way include .h + .c for stack or other*/
// safe for use in just one file 
struct Node; // forward declaration

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

struct Node *peek(stack *s)
{
    if (isEmpty(s)) return NULL; // error code
    return (s->arr[s->top]);
}
