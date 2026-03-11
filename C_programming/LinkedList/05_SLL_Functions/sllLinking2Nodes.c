/* creating 2 node and linking them */
#include <stdio.h>
#include <stdlib.h>

struct sll
{
    int val;
    struct sll *next;
};

int main()
{

    struct sll *head = NULL, *curr = NULL;

    head = (struct sll *)malloc(sizeof(struct sll));
    if (head == NULL)
    {
        printf("\nMemory allocation failed!!");
        exit(0);
    }

    head->val = 25;
    head->next = NULL;

    curr = (struct sll *)malloc(sizeof(struct sll));
    if (curr == NULL)
    {
        printf("\nMemory allocation failed!!");
        exit(0);
    }

    curr->val = 35;
    curr->next = NULL;

    // linking head to curr
    head->next = curr;

    /* printing the list */
    struct sll *temp = head;
    while (temp != NULL)
    {
        printf(" %d ", temp->val);
        temp = temp->next;
    }

   

    return 0;
}