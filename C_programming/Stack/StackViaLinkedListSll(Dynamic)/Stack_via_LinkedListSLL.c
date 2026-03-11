/* Stack via linked list (Dynamic) */
#include <stdio.h>
#include <stdlib.h>

// node struct
struct Node
{
    int data;
    struct Node *next;
};

// stack 
struct stack
{
    struct Node *top;
};

// function prototypes
void init(struct stack *s);
int isEmpty(struct stack *s);
void push(struct stack *s, int item);
int pop(struct stack *s);
void display(struct stack *s);
int peek(struct stack *s);

int main()
{
    struct stack s;
    init(&s);            // initialize stack

    printf("Pushing elements 10, 20, 30 onto stack...\n");
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    display(&s);

    return 0;
    //
}

// initialization
void init(struct stack *s)
{
    s->top = NULL;
}

// empty check
int isEmpty(struct stack *s)
{
    return (s->top == NULL);
}

// push
void push(struct stack *s, int item)
{
    struct Node *newNode = malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = item;
    newNode->next = s->top;
    s->top = newNode;
}

// pop
int pop(struct stack *s)
{
    if (isEmpty(s))
        return -1; // error code
    struct Node *temp = s->top;
    int delitem = temp->data;
    s->top = temp->next;
    free(temp);
    return delitem;
}

// display
void display(struct stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is Empty!!\n");
        return;
    }
    struct Node *curr = s->top;
    while (curr != NULL)
    {
        printf(" %d\n", curr->data);
        curr = curr->next;
    }
}

// peek
int peek(struct stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty!!\n");
        return -1; // error code
    }
    return (s->top->data);
}