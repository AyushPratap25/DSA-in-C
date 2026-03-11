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

/* deleting first node */
struct sll *delBeginning(struct sll *head, int *delitem)
{
    // list empty
    if (head == NULL)
    {
        printf("List is empty");
        *delitem = -1; // error code
        return NULL;
    }

    struct sll *curr = head;
    head = head->next;

    // allocating the value to the delitem
    *delitem = curr->val;
    // free the curr the old head node
    free(curr);
    return head;
}