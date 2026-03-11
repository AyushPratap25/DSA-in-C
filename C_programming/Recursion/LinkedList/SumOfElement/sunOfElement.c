#include <stdio.h>

struct Node
{
    int data;
    struct Node *next;
};

int sum(struct Node *head)
{
    if (head == NULL)
        return 0;
    return (head->data + sum(head->next));
};

int main() {
    // your code here
    return 0;
}