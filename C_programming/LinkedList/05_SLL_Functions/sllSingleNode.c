/* Single linked list with one node */
#include <stdio.h>
#include <stdlib.h>

// structure for single linked list
struct sll
{
    int val;
    struct sll *next;
};

int main()
{
    struct sll *new = NULL; // avoid

    new = (struct sll *)malloc(sizeof(struct sll));
    if (new == NULL)
    {
        printf("Memory allocation failed\n");
        exit(0);
    }

    printf("Enter the value for node new: ");
    scanf("%d", &new->val);

    new->next = NULL;

    printf("Node created → val = %d, next = %p\n", new->val, new->next);

    free(new);

    return 0;
}