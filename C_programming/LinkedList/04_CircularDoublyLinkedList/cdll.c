// Circular Double Linked List
#include <stdio.h>
#include <stdlib.h>

// struct
struct cdll
{
    struct cdll *prev;
    int data;
    struct cdll *next;
};

void freeList(struct cdll *head)
{
    if (head == NULL)
        return;
    struct cdll *curr = head;
    struct cdll *temp = NULL;
    do
    {
        temp = curr;
        curr = curr->next;
        free(temp);
    } while (curr != head);
}

struct cdll *createCdll(int n)
{
    if (n <= 0)
        return NULL;

    struct cdll *head = malloc(sizeof(struct cdll));
    if (head == NULL)
        return NULL;

    printf("Enter Node 1 data: ");
    scanf("%d", &head->data);
    head->next = head;
    head->prev = head;

    struct cdll *curr = head;
    for (int i = 2; i <= n; i++)
    {
        struct cdll *newNode = malloc(sizeof(struct cdll));
        if (newNode == NULL)
        {
            freeList(head);
            return NULL;
        }

        printf("Enter Node %d data: ", i);
        scanf("%d", &newNode->data);

        curr->next = newNode;
        newNode->prev = curr;
        newNode->next = head;
        head->prev = newNode;
        curr = newNode;
    }

    return head;
}

struct cdll *insertAtBeginning(struct cdll *head, int item)
{
    struct cdll *newNode = malloc(sizeof(struct cdll));
    if (newNode == NULL)
        return head;

    newNode->data = item;

    if (head == NULL)
    {
        newNode->next = newNode;
        newNode->prev = newNode;
        return newNode;
    }

    struct cdll *tail = head->prev;

    newNode->next = head;
    head->prev = newNode;

    tail->next = newNode;
    newNode->prev = tail;

    return newNode; // new head
}

struct cdll *insertAtEnd(struct cdll *head, int item)
{
    struct cdll *newNode = malloc(sizeof(struct cdll));
    if (newNode == NULL)
        return head;

    newNode->data = item;

    if (head == NULL)
    {
        newNode->next = newNode;
        newNode->prev = newNode;
        return newNode;
    }

    struct cdll *tail = head->prev;

    tail->next = newNode;
    newNode->prev = tail;

    newNode->next = head;
    head->prev = newNode;

    return head;
}

struct cdll *delAtBeginning(struct cdll *head)
{
    // list empty
    if (head == NULL)
        return NULL;

    // only one node
    if (head->next == head)
    {
        free(head);
        return NULL;
    }

    // more than one node
    struct cdll *newHead = head->next; // new Head
    struct cdll *tail = head->prev;    // last node as the tail

    free(head);

    // connection
    newHead->prev = tail;
    tail->next = newHead;

    return newHead;
}

struct cdll *delAtEnd(struct cdll *head)
{
    // list empty
    if (head == NULL)
        return NULL;

    // only one node
    if (head->next == head)
    {
        free(head);
        return NULL;
    }

    struct cdll *secondLast = head->prev->prev; // at 2nd last node
    struct cdll *tail = secondLast->next; // last node 
    
    // connection
    secondLast->next = head;
    head->prev = secondLast;
    
    free(tail);

    return head;
}

int count(struct cdll *head)
{
    if (head == NULL) return 0;
    int count = 0;
    struct cdll *curr = head;
    do 
    {
        count += 1;
        curr = curr->next;
    } while (curr != head);

    return count;
}

void display(struct cdll *head)
{
    if (head == NULL)
    {
        printf("CDLL is Empty!\n");
        return;
    }
    struct cdll *curr = head;
    printf("(Back to tail) <-> ");
    do
    {
        printf("%d <-> ", curr->data);
        curr = curr->next;
    } while (curr != head);
    printf("(back to head)\n");
}

int main()
{
    struct cdll *head = NULL;
    head = createCdll(5);
    display(head);

    head = insertAtBeginning(head, 20);
    display(head);

    head = insertAtEnd(head, 100);
    display(head);

    head = delAtBeginning(head);
    display(head);

    head = delAtEnd(head);
    display(head);

    printf("%d\n", count(head));
    
    return 0;
}