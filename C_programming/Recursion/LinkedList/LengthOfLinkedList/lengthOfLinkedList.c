#include <stdio.h>

struct Node
{
    struct Node *next;
};

int lenLinkedList(struct Node *head)
{
    if (head == NULL)
        return 0;
    return (1 + lenLinkedList(head->next));
}

int main()
{

    return 0;
}