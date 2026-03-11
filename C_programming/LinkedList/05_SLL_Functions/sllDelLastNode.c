#include <stdio.h>
#include <stdlib.h>

struct sll
{
    int val;
    struct sll *next;
};

int main()
{
    // your code here
    return 0;
}

/* delete the last node of the sll */
struct sll *deleteLastNode(struct sll *head, int *delitem)
{
    // list is empty
    if (head == NULL)
    {
        printf("\nList is Empty!!");
        *delitem = -1; // error code
        return NULL;
    }

    // one node exist
    if (head->next == NULL)
    {
        *delitem = head->val;
        free(head);
        return NULL;
    }

    // more than one node exist
    struct sll *curr = head;
    while (curr->next->next != NULL)
    {
        curr = curr->next;
    }
    *delitem = curr->next->val;
    // free takes the address and points to it and frees that area here the last node
    free(curr->next);
    // setting the 2nd last node next var value to NULL
    curr->next = NULL;

    return head;
}
