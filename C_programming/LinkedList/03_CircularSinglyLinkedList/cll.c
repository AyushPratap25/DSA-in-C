// CLL
/* Note : free (ptr) does not makes ptr null it just tells the system that the memory is no more used for personal and system can use it meawhile the address and everthing still exists and a pointer can point to it, so incase of circular LL its imp to write curr != head insted of curr != NULL which is wrong. Take care of this and go for do while loop as best suited*/

#include <stdio.h>
#include <stdlib.h>

// cll struct
struct cll
{
    int data;
    struct cll *next;
};

void freeList(struct cll *head)
{
    if (head == NULL)
        return;

    struct cll *curr = head;
    struct cll *nextNode = NULL;
    do
    {
        nextNode = curr->next;
        free(curr);
        curr = nextNode;
    } while (curr != head);
}

struct cll *createCLL(int n) // n no. of nodes
{
    struct cll *head = malloc(sizeof(struct cll));
    if (head == NULL)
        return NULL;

    printf("Enter Node 1 data: ");
    scanf("%d", &head->data);
    head->next = head; // circular

    struct cll *curr = head;
    for (int i = 2; i <= n; i++)
    {
        struct cll *newNode = malloc(sizeof(struct cll));
        if (newNode == NULL)
        {
            printf("Memory allocation failed!\n");
            freeList(head);
            return NULL;
        }

        printf("Enter Node %d data: ", i);
        scanf("%d", &newNode->data);

        newNode->next = head;
        curr->next = newNode;
        curr = newNode;
    }

    return head;
}

struct cll *insertAtBeginning(struct cll *head, int item)
{
    struct cll *newNode = malloc(sizeof(struct cll));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return head;
    }

    newNode->data = item;

    if (head == NULL)
    {
        newNode->next = newNode;
        return newNode;
    }
    struct cll *curr = head;
    do
    {
        curr = curr->next;
    } while (curr->next != head);

    curr->next = newNode;
    newNode->next = head;

    return newNode;
}

struct cll *insertAtEnd(struct cll *head, int item)
{
    // newNode
    struct cll *newNode = malloc(sizeof(struct cll));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return head;
    }

    newNode->data = item;

    // list empty
    if (head == NULL)
    {
        newNode->next = newNode;
        return newNode;
    }
    // traverse till end and insert
    struct cll *curr = head;
    do
    {
        curr = curr->next;
    } while (curr->next != head);

    curr->next = newNode;
    newNode->next = head;

    return head;
}

struct cll *delAtBeginning(struct cll *head)
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
    struct cll *newHead = head->next;
    struct cll *curr = head;
    do
    {
        curr = curr->next;
    } while (curr->next != head);

    curr->next = newHead;
    free(head);

    return newHead;
}

struct cll *delAtEnd(struct cll *head)
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
    struct cll *curr = head;
    do
    {
        curr = curr->next;
    } while (curr->next->next != head);

    // free node
    struct cll *temp = curr->next;
    free(temp);

    // make list circular
    curr->next = head;

    return head;
}

int countNode(struct cll *head)
{
    int count = 0;
    struct cll *curr = head;
    do
    {
        count += 1;
        curr = curr->next;
    } while (curr != head);

    return count;
}

void display(struct cll *head)
{
    if (head == NULL)
    {
        printf("CLL is Empty!\n");
        return;
    }
    struct cll *curr = head;
    do
    {
        printf("%d -> ", curr->data);
        curr = curr->next;
    } while (curr != head);
    printf("(back to head)\n");
}

/* A dangling pointer is a pointer that still points to a memory location that has been freed or deallocated. Accessing or modifying memory through a dangling pointer is undefined behavior and can cause crashes, data corruption, or other bugs. */

int main()
{
    struct cll *head = NULL;
    head = createCLL(4);
    display(head);

    head = insertAtBeginning(head, 20);
    display(head);

    head = insertAtEnd(head, 111);
    display(head);

    head = delAtBeginning(head);
    display(head);

    head = delAtEnd(head);
    display(head);

    printf("%d \n", countNode(head));

    freeList(head);

    head = NULL; // safe, to avoid dangling ptr
    return 0;
}