// linked list
#include <stdio.h>
#include <stdlib.h>

// linked list struct
struct sll
{
    int val;
    struct sll *next;
};

// Function prototypes for singly linked list (SLL)
struct sll *createSll(int n);
void display(struct sll *head);
struct sll *insertAtBeginning(struct sll *head, int item);
struct sll *insertAtEnd(struct sll *head, int item);
struct sll *delAtBeginning(struct sll *head, int *delitem);
struct sll *delAtEnd(struct sll *head, int *delitem);
void bubbleSort(struct sll *head);
int countNode(struct sll *head);
void freeList(struct sll *head);

int main()
{
    struct sll *head = NULL;
    head = createSll(4);
    head = insertAtEnd(head, 20);

    printf("\n");

    head = delAtBeginning(head, NULL);
    display(head);

    printf("count: %d", countNode(head));
    return 0;
}

// create sll
struct sll *createSll(int n)
{
    if (n <= 0)
        return NULL;

    struct sll *head = malloc(sizeof(struct sll));
    if (head == NULL)
    {
        printf("Memory allocation failed!!\n");
        return NULL;
    }

    printf("Enter node 1 val: ");
    scanf("%d", &head->val);
    head->next = NULL;

    struct sll *curr = head;
    for (int i = 2; i <= n; i++)
    {
        struct sll *newNode = malloc(sizeof(struct sll));
        if (newNode == NULL)
        {
            printf("Memory allocation failed!!\n");
            // if any node creation fails then deallocating all the nodes
            // basically the sll to avoid partial node creation
            freeList(head);
            return NULL;
            // NULL for empty list since node creation at one point or other failed
        }

        printf("Enter node %d val: ", i);
        scanf("%d", &newNode->val);
        newNode->next = NULL;
        curr->next = newNode;
        curr = newNode;
    }
    return head;
}

// display
void display(struct sll *head)
{
    if (head == NULL)
    {
        printf("List is Empty!\n");
        return;
    }

    struct sll *curr = head;
    while (curr != NULL)
    {
        printf("%d -> ", curr->val);
        curr = curr->next;
    }
    printf("NULL\n");
}

// insert at beginning
struct sll *insertAtBeginning(struct sll *head, int item)
{
    struct sll *newNode = (struct sll *)malloc(sizeof(struct sll));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return head;
    }

    newNode->val = item;
    newNode->next = head;

    return newNode;
}

// insert at end
struct sll *insertAtEnd(struct sll *head, int item)
{
    struct sll *newNode = (struct sll *)malloc(sizeof(struct sll));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return head;
    }
    newNode->val = item;
    newNode->next = NULL;

    if (head == NULL)
        return newNode;

    struct sll *curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = newNode;

    return head;
}

// del at beginning
struct sll *delAtBeginning(struct sll *head, int *delitem)
{
    if (head == NULL)
        return NULL;

    struct sll *nextNode = head->next;
    if (delitem) // only if not NULL
        *delitem = head->val;

    free(head);
    return nextNode;
}

// delAtEnd
struct sll *delAtEnd(struct sll *head, int *delitem)
{
    // list empty
    if (head == NULL)
        return NULL;

    // one node exists
    if (head->next == NULL)
    {
        if (delitem != NULL)
            *delitem = head->val;

        free(head);
        return NULL;
    }

    // multiple nodes exists
    struct sll *curr = head;
    while (curr->next->next != NULL)
    {
        curr = curr->next;
    }

    struct sll *temp = curr->next;
    curr->next = NULL;

    if (delitem != NULL)
        *delitem = temp->val;

    free(temp);
    return head;
}

// node count
int countNode(struct sll *head)
{
    int count = 0;
    struct sll *curr = head;
    while (curr != NULL)
    {
        count++;
        curr = curr->next;
    }
    return count;
}

// free list
void freeList(struct sll *head)
{
    while (head != NULL)
    {
        struct sll *nextNode = head->next;
        free(head);
        head = nextNode;
    }
}

// search item
int search(struct sll *head, int item)
{
    if (head == NULL)
        return 0;

    struct sll *curr = head;
    while (curr != NULL)
    {
        if (curr->val == item)
            return 1; // search successful
        curr = curr->next;
    }

    return 0; // search unsuccessful
}

// buble sort sll
void bubbleSort(struct sll *head)
{
    if (head == NULL)
        return;

    struct sll *last = NULL;
    int swapped = 0; // flag
    do
    {
        struct sll *curr = head;
        swapped = 0;
        while (curr->next != last)
        {
            if (curr->val > curr->next->val)
            {
                int temp = curr->val;
                curr->val = curr->next->val;
                curr->next->val = temp;
                swapped = 1;
            }
            curr = curr->next;
        }

        last = curr;
    } while (swapped);
}

// sll reverse
struct sll *reverseSll(struct sll *head)
{
    struct sll *prev = NULL;
    struct sll *curr = head;
    struct sll *nextNode = NULL;

    while (curr != NULL)
    {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}