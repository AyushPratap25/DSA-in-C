// sll
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct sll
{
    struct node *head;
};


struct node *createSll(struct sll *list, int n)
{
    if (n <= 0)
    {
        list->head = NULL;
        return;
    }
    
    // head node
    struct node *head = malloc(sizeof(struct node));
    if (head == NULL)
    {
        printf("memory allocation failed!\n");
        return NULL;
    }

    printf("Enter node 1 data: ");
    scanf("%d", &head->data);
    head->next = NULL;

    struct sll *list = head;
    
    struct node *curr = head;
    for (int i = 2; i <= n; i++)
    {
        // new node
        struct node *newNode = malloc(sizeof(struct node));
        if (newNode == NULL)
        {
            printf("Memory allocation failed!\n");
            return NULL;
        }
        printf("Enter node %d data: ", i);
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        // chain
        curr->next = newNode;
        curr = newNode;
    }

    return head;
}

void display(struct node *head)
{
    struct node *trav = head;
    printf("head->");
    while (trav != NULL)
    {
        printf("%d->", trav->data);
        trav = trav->next;
    }
    printf("NULL\n");
}

struct node *insertAtBeginning(struct sll *list, int item)
{
    // node
    struct node *newNode = malloc(sizeof(struct node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return list->head;
    }
    newNode->data = item;
    newNode->next = list->head;
    return newNode;
}

struct node *insertAtEnd(struct node *head, int item)
{
    // node
    struct node *newNode = malloc(sizeof(struct node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return head;
    }
    newNode->data = item;
    newNode->next = NULL;

    if (head == NULL)
    {
        return newNode;
    }

    struct node *curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = newNode;
    
    return head;
}









int main()
{

    struct node *head = NULL;
    // head = createSll(4);

    display(head);
    
    head = insertAtBeginning(head, 78);
    head = insertAtEnd(head, 100);
    
    display(head);

    return 0;
}