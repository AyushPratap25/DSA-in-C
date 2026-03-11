#include <stdio.h>
#include <stdlib.h>

// struct dll
struct dll
{
    int data;
    struct dll *prev;
    struct dll *next;
};

// function prototypes
struct dll *createDll(int n);
struct dll *insertAtBeginning(struct dll *head, int item);
struct dll *insertAtEnd(struct dll *head, int item);
struct dll *delAtBeginning(struct dll *head, int *delitem);
struct dll *delAtEnd(struct dll *head, int *delitem);
void freeDll(struct dll *head);
void display(struct dll *head);
int nodeCount(struct dll *head);

int main()
{
    struct dll *head = NULL;
    head = createDll(4);
    // head = insertAtBeginning(head, 45);
    // head = insertAtEnd(head, 200);
    // head = delAtBeginning(head, NULL);
    // int delitem;
    // head = delAtEnd(head, &delitem);
    // printf("\nDelitem : %d\n", delitem);
    // printf("count : %d", nodeCount(head));
    display(head);

    return 0;
}

// create n node
struct dll *createDll(int n)
{
    // input check
    if (n <= 0) return NULL;

    struct dll *head = malloc(sizeof(struct dll));
    if (head == NULL)
    {
        printf("Memory allocation failed!!\n");
        return NULL;
    }

    printf("\nEnter node 1 data: ");
    scanf("%d", &head->data);

    head->prev = NULL;
    head->next = NULL;

    struct dll *curr = head;
    for (int i = 2; i <= n; i++)
    {
        struct dll *newNode = malloc(sizeof(struct dll));
        if (newNode == NULL)
        {
            printf("Memory allocation failed!!\n");
            freeDll(head);
            return NULL;
        }

        printf("\nEnter node %d data: ", i);
        scanf("%d", &newNode->data);

        newNode->prev = curr;
        newNode->next = NULL;

        curr->next = newNode;
        curr = newNode;
    }

    return head;
}

// free list
void freeDll(struct dll *head)
{
    while (head != NULL)
    {
        struct dll *nextNode = head->next;
        free(head);
        head = nextNode;
    }
}

// display
void display(struct dll *head)
{
    if (head == NULL)
    {
        printf("List is empty!!\n");
        return;
    }
    struct dll *curr = head;
    while (curr != NULL)
    {
        printf("%d <-> ", curr->data);
        curr = curr->next;
    }
    // clean end
    printf("NULL\n");
}

// insert at beginning
struct dll *insertAtBeginning(struct dll *head, int item)
{
    struct dll *newNode = (struct dll *)malloc(sizeof(struct dll));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!!\n");
        return head;
    }

    newNode->data = item;
    newNode->prev = NULL;
    newNode->next = head;

    // if list empty
    if (head != NULL)
    {
        head->prev = newNode;
    }

    return newNode;
}

// insert at end
struct dll *insertAtEnd(struct dll *head, int item)
{
    struct dll *newNode = (struct dll *)malloc(sizeof(struct dll));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return head;
    }

    newNode->data = item;
    newNode->next = NULL;
    // if list empty
    if (head == NULL)
    {
        newNode->prev = NULL;
        return newNode;
    }

    struct dll *curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }

    curr->next = newNode;
    newNode->prev = curr;

    return head;
}

// del at beginning
struct dll *delAtBeginning(struct dll *head, int *delitem)
{
    if (head == NULL)
        return NULL; // list empty
    

    if (head->next == NULL)
    {
        if (delitem)
            *delitem = head->data;
    
        free(head);
        return NULL;
    }

    if (delitem)
        *delitem = head->data;
    
    // store old head in temp and then free, for readability
    struct dll *temp = head;
    // new head
    head = head->next;
    head->prev = NULL;
    free(temp);

    return head;
}

// del at the end
struct dll *delAtEnd(struct dll *head, int *delitem)
{
    if (head == NULL)
    {
        return NULL;
    }

    // one node exists
    if (head->next == NULL)
    {
        if (delitem)
            *delitem = head->data;
        free(head);
        return NULL;
    }
    // multiple node exists
    struct dll *curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }

    if (delitem)
        *delitem = curr->data;
    
    curr->prev->next = NULL;
    free(curr);

    return head;
}

// node count
int nodeCount(struct dll *head)
{
    int count = 0;
    struct dll *trav = head;

    while (trav != NULL)
    {
        count += 1;
        trav = trav->next;
    }

    return count;
}
