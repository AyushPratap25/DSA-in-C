/* Infix to Postfix conversion */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100

int top = -1; // intially the stack is empty so -1
char st[MAX]; // stack

// function prototype stack
int isEmpty();              // empty
int isFull();               // full
void push(char st[], char); // push
char pop(char st[]);        // pop and return

// infixToPostfix function prototype
int priority(char);
void infixToPostfix(char infix[], char postfix[]);

int main()
{

    char infix[MAX];
    char postfix[MAX];

    printf("\n\nEnter the infix expression: ");
    scanf("%s", infix); // in case of %s no & take care of this :)

    infixToPostfix(infix, postfix);

    printf("%s", postfix);

    return 0;
}

/* function definition */
// stack is empty
int isEmpty()
{
    return (top == -1);
}

// stack is full
int isFull()
{
    return (top == MAX - 1);
}

// push
void push(char s[], char item)
{
    if (isFull())
    {
        printf("Stack is full (Overflow!!)");
        return;
    }
    s[++top] = item;
}

// pop and return the item
char pop(char s[])
{
    int temp;
    if (isEmpty())
    {
        printf("Stack is empty!!\n");
        return '\0';
    }
    return (s[top--]);
}

// infix postifix
int priority(char op)
{
    if (op == '+' || op == '-')
    {
        return (1);
    }
    else if (op == '*' || op == '/' || op == '%')
    {
        return (2);
    }
    else if (op == '^')
    {
        return (3);
    }
    else
    {
        return (-1);
    }
}

void infixToPostfix(char infix[], char postfix[])
{
    int length;
    length = strlen(infix);
    int i;
    int k = 0;
    for (i = 0; i < length; i++)
    {
        // operand
        // can use isalnum() from <ctype.h>
        if ((infix[i] >= 'A' && infix[i] <= 'Z') || (infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= '0' && infix[i] <= '9'))
        {
            postfix[k++] = infix[i];
        }

        // (
        else if (infix[i] == '(')
        {
            push(st, infix[i]);
        }

        // )
        else if (infix[i] == ')')
        {
            while (!(isEmpty()) && st[top] != '(')
            {
                postfix[k++] = pop(st);
            }
            pop(st); // the '(' to balance both the parenthesis
        }

        // operator
        else
        {
            while (!(isEmpty()) && priority(infix[i]) <= priority(st[top]))
            {
                postfix[k++] = pop(st);
            }
            push(st, infix[i]);
        }
    }

    while (!isEmpty())
    {
        postfix[k++] = pop(st);
    }
    postfix[k] = '\0'; // null-terminate
}
