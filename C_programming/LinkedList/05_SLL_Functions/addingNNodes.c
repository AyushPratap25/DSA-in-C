/* Adding n nodes through user input */
#include <stdio.h>
#include <stdlib.h>

// struct of sll
struct sll
{
    int val;
    struct sll *next;
};

int main()
{
    struct sll *head = NULL, *curr = NULL;
    int n;

    head = (struct sll *)malloc(sizeof(struct sll));
    if (head == NULL)
    {
        printf("\nMemory allocation failed!!");
        exit(0);
    }

    printf("\nEnter the head node value: ");
    scanf("%d", &head->val);
    head->next = NULL;

    printf("\nEnter the no of node to create: ");
    scanf("%d", &n);

    curr = head;

    for (int i = 1; i <= n; i++)
    {
        struct sll *newNode = NULL;
        newNode = (struct sll *)malloc(sizeof(struct sll));
        if (newNode == NULL)
        {
            printf("\nMemory allocation failed!!");
            exit(0);
        }

        printf("\nEnter the node %d value: ", i);
        scanf("%d", &newNode->val);
        newNode->next = NULL;

        curr->next = newNode;
        curr = newNode;
    }

    // display
    struct sll *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->val);
        temp = temp->next;
    }
    printf("NULL\n");

    // freeing the memory
    temp = head;
    while (temp != NULL)
    {
        struct sll *nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }

    return 0;
}
