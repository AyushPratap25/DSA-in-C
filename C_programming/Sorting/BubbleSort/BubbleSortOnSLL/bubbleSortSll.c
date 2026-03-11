#include <stdio.h>
#include <stdlib.h>

// sll struct
struct sll
{
    int data;
    struct sll *next;
};

// bubble sort
void bubbleSortSll(struct sll *head)
{
    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    struct sll *last = NULL;
    int swapped;
    do
    {
        swapped = 0;
        struct sll *curr = head;
        while (curr->next != last)
        {
            if (curr->data > curr->next->data)
            {
                int temp = curr->data;
                curr->data = curr->next->data;
                curr->next->data = temp;
                swapped = 1;
            }
            curr = curr->next;
        }
        last = curr;
    } while (swapped);
}

/* --------SLL Creation and display, freelist function-------- */
void freeList(struct sll *head)
{
    struct sll *curr = head;
    struct sll *nextNode = NULL;
    while (curr != NULL)
    {
        nextNode = curr->next;
        free(curr);
        curr = nextNode;
    }
}

struct sll *createSll(int n)
{
    struct sll *head = malloc(sizeof(struct sll));
    if (head == NULL)
    {
        printf("Memory alloaction failed!\n");
        return NULL;
    }

    printf("Enter node 1 val: ");
    scanf("%d", &head->data);
    head->next = NULL;

    struct sll *curr = head;
    for (int i = 2; i <= n; i++)
    {
        struct sll *newNode = malloc(sizeof(struct sll));
        if (newNode == NULL)
        {
            printf("Memory allocation failed!\n");
            freeList(head);
            return head;
        }
        printf("Enter node %d val: ", i);
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        // linking
        curr->next = newNode;
        curr = newNode;
    }
    return head;
}

void display(struct sll *head)
{
    struct sll *curr = head;
    while (curr != NULL)
    {
        printf("%d <-> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

int main()
{
    struct sll *head = NULL;
    head = createSll(5);
    display(head);

    bubbleSortSll(head);
    display(head);

    // free memory
    freeList(head);
    return 0;
}