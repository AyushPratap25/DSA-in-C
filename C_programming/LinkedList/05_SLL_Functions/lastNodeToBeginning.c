#include <stdio.h>

struct sll
{
    int val;
    struct sll *next;
};

int main() {
    // your code here
    return 0;
}

struct sll *lastToBeginning(struct sll *head)
{
    struct sll *curr = head;

    if (head == NULL)
    {
        printf("List empty");
        return NULL;
    }

    if (head->next == NULL)
    {
        printf("only one list exist!!");
        return NULL;
    }

    while (curr->next->next != NULL)
    {
        curr = curr->next;
    }

    curr->next->next = head;
    head = curr->next;
    curr->next = NULL;

    return head;
}