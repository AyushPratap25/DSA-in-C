/* Stack via structure and pointer */
#include <stdio.h>
#define MAX 10

// stack structure
typedef struct
{
    int arr[MAX];
    int top;
} stack;

// top initialisation
void init(stack *s)
{
    s->top = -1;
}

// check if stack is empty
int isEmpty(stack *s)
{
    return (s->top == -1);
}

// check if stack is full
int isFull(stack *s)
{
    return (s->top == MAX - 1);
}

// push item at the top of the stack if not full
void push(stack *s, int item)
{
    if (isFull(s))
    {
        printf("Stack is full!\n");
        return;
    }
    s->arr[++(s->top)] = item;
}

// pop item from the top of the stack if not empty
int pop(stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is Empty!!\n");
        return -1; // error code
    }
    return (s->arr[(s->top)--]);
}

// display the stack if not empty or print empty iff it is
void display(stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty!\n");
        return;
    }
    for (int i = s->top; i >= 0; i--)
    {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}

// return the peak element if not empty or else print empty
int peek(stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty!\n");
        return -1; // error code
    }
    return (s->arr[s->top]);
}

int main()
{
    // stack s1, s2, s3; multiple stack struct
    // init(&s1);
    // init(&s2);
    // init(&s3);

    /* array of struct */
    // stack s[3];
    // for (int i = 0; i < 3; i++)
    //      init(&s[i]);
    // push (&s[1], 23); and so on....
    stack s1;
    init(&s1);
    push(&s1, 25);
    push(&s1, 8);
    pop(&s1);
    pop(&s1);
    printf("%d", pop(&s1));
    // display(&s1);
    return 0;
}

