// stack
#include <stdio.h>
#define max 10 // this is preprocessor directive there should be no semicolon (mistake committed)

int top = -1; // intially the stack is empty so -1
int s[max];   // stack

// function prototype
int isEmpty();           // empty
int isFull();            // full
void push(int s[], int); // push
int pop(int s[]);        // pop and return
void display(int s[]);   // display

// main begin
int main()
{
    int choice;

    while (1) // loop (1 -> true)
    {
        printf("\n\n\t***STACK MENU***\n");
        printf("1.Push\n2.Pop\n3.Display\n4.Exit\n");

        // enter your choice
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        // operation on stack according to choice
        int item;
        switch (choice)
        {
        // push
        case 1:
            printf("\nEnter item to push: ");
            scanf("%d", &item); // don't forget &
            push(s, item);
            break;
        // pop
        case 2:
            item = pop(s);
            if (item != -1) // mark this condition it's important
                printf("\nPopped item: %d", item);
            break;
        // display
        case 3:
            display(s);
            break;
        // exit
        case 4:
            return 0; // exit program
        // invalid input
        default:
            printf("\nEnter valid choice :/");
        }
    }
}
// main end

// function definition
// stack is empty
int isEmpty() // no need for s[] parameter as we are not using it in the function
{
    if (top == -1)
        return 1; // as 1 means true for if isEmpty(), if no == provided
    else
        return 0;
}

// stack is full
int isFull()
{
    if (top == (max - 1))
        return 1; // as 1 means true for <if <isEmpty()>>, if no == provided
    else
        return 0;
}

// push
void push(int s[], int item)
{
    if (isFull())
        printf("Stack is full (Overflow!!)");
    else
    {
        s[++top] = item;
        printf("Operation successful!!");
    }
}

// pop and return the item
int pop(int s[])
{
    int temp;
    if (isEmpty())
    {
        printf("Stack is empty (Underflow!!)");
        return -1; // makes sure to return, -1 for failure or here underdlow
    }
    else
    {
        return (s[top--]); // once returned the function execution stops there
    }
}

// display (traverse)
void display(int s[])
{
    if (isEmpty())
    {
        printf("Stack is empty!!");
        return;
    }
    // print the values
    for (int i = top; i >= 0; i--)
    {
        printf("\t |%d", s[i]);
    }
}