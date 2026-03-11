// need to improve a bit for more than one digit eval
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // for isdigit()
#define MAX 100

#pragma region Stack Struct
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

// push element to stack
void push(stack *s, int item)
{
    if (isFull(s))
    {
        printf("Stack is Full!!\n");
        return;
    }
    s->arr[++(s->top)] = item;
}

// pop element from stack
int pop(stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is Empty!!\n");
        return 0;
    }
    return (s->arr[(s->top)--]);
}
#pragma endregion

// function to evaluate postfix expression
int evalPostfix(char exp[])
{
    stack s1;
    init(&s1);
    int i = 0, a, b;

    while (exp[i] != '\0')
    {
        if (isdigit(exp[i]))
        {
            push(&s1, exp[i] - '0'); // convert char to int
        }
        else
        {
            a = pop(&s1);
            b = pop(&s1);

            switch (exp[i])
            {
            case '+': push(&s1, b + a); break;
            case '-': push(&s1, b - a); break;
            case '*': push(&s1, b * a); break;
            case '/': push(&s1, b / a); break;
            }
        }
        i++;
    }
    return pop(&s1); // final result in the stack
}

int main()
{
    
    char postfixExp[100];
    printf("Enter Postfix Expression: ");
    scanf("%s", postfixExp);

    printf("Result = %d\n", evalPostfix(postfixExp));
    return 0;
}
