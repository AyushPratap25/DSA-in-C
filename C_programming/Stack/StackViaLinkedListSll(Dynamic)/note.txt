NOTE: read the concept first before jumping to create the code, as it helps in avoding
confusions and better and fast study process; After that like work on creating the code

Stack is just the combination of 
1. Push = insertionAtBeginning
2. Pop  = delAtBeginning


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
Taking `top` Pointer Inside a Struct

Taking the `top` pointer inside a struct for a stack is highly beneficial. Using this approach:

- Multiple stacks can be created and managed easily inside main().
- Each stack maintains its own `top` pointer, just like a linked list maintains its head pointer.

Example:

// SLL
struct sll *head = NULL;  // points to the head of the list

// Stack via linked list
struct stack {
    struct Node *top;  // points to the top of the stack
};

Note:
- Using a global head or top pointer limits you to a single list/stack.
- Keeping top inside a structure allows creating multiple stacks inside main(), each managing its own top independently.
- This approach makes code cleaner, modular, and more extensible.

Reference:
- See the program "Stack via Linked List" for a practical example.
