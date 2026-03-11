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

struct sll *insertAtBegin(struct sll *head, int n)
{
    struct sll *newNode = NULL;
    newNode = (struct sll *)malloc(sizeof(struct sll));

    if (newNode == NULL)
    {
        printf("\nMemory allocation failed");
        exit(0);
    }

    newNode->val = n;

    newNode->next = head;
    head = newNode;

    return (head);
}
