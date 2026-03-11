// stack DS 
/* 
init
isEmpty
isFull
push
pop
display
 */
#include <stdio.h>
#define MAX 10

typedef struct
{
    int arr[MAX];
    int top;
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

void push(stack *s, int item)
{
    if (isFull(s))
    {
        printf("Full!\n");
        return;
    }
    s->arr[++(s->top)] = item;
}

int pop(stack *s)
{
    if (isEmpty(s))
    {
        printf("stack is emtpty!\n");
        return -1; // error code
    }
    return (s->arr[(s->top)--]);
}

void display(stack *s)
{
    if (isEmpty(s))
    {
        printf("stack is empty!\n");
        return;
    }
    
    printf("top->");
    for (int i = s->top; i >= 0; i--)
    {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}


// main
int main()
{
    stack s1;
    init(&s1);

    display(&s1);
    push(&s1, 20);
    push(&s1, 10);
    push(&s1, 70);
    
    display(&s1);
    
    int item = pop(&s1);
    printf("%d \n", item);
    
    display(&s1);

    return 0;
}