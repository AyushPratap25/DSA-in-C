/* Adding n nodes through user input */
#include <stdio.h>
#include <stdlib.h>

// struct of sll
struct sll
{
    int val;
    struct sll *next;
};

// function prototype
struct sll *createList(int);
void display(struct sll *);
void freeList(struct sll *);

int main()
{
    struct sll *head;
    int n;

    // input no of nodes to create
    printf("\nEnter no of node to create excluding the head node: ");
    scanf("%d", &n);

    // function call
    head = createList(n);
    display(head);
    freeList(head);

    return 0;
}

// funciton to create n nodes making sure to return head, address to first node
struct sll *createList(int n)
{
    // active argument check
    if (n <= 0) return NULL;

    struct sll *head = NULL, *curr = NULL;

    // create head node
    // memory allocation
    head = (struct sll *)malloc(sizeof(struct sll));
    // alocation check
    if (head == NULL)
    {
        printf("\nMemory allocation failed!!");
        return NULL;
    }

    // enter head node value
    printf("\nEnter the head, 1st node value: ");
    scanf("%d", &head->val);
    head->next = NULL; // very imp step

    // allocating head node address to curr for traversing
    curr = head;

    // loop to create n no. of nodes
    for (int i = 2; i <= n; i++)
    {
        // create new node
        struct sll *newNode = NULL;
        // memory allocation
        newNode = (struct sll *)malloc(sizeof(struct sll));
        // allocation check
        if (newNode == NULL)
        {
            printf("\nMemory allocation failed!!");
            return head;
        }

        // node value entry
        printf("\nEnter node %d value: ", i);
        scanf("%d", &newNode->val);
        newNode->next = NULL; // setting next to NULL Very Important

        // linking the prev node with the newly created node
        curr->next = newNode;
        // moving pointer to the just created newly node, storing its address in curr
        curr = newNode;
    }
    // return head node address 
    return head;
}

// display linked list
void display(struct sll *head)
{
    // display
    struct sll *temp = head;
    printf("\n");
    // traversing till NULL
    while (temp != NULL)
    {
        printf("%d -> ", temp->val);
        temp = temp->next; 
    }
    printf("NULL\n");
}

// freeing memory
void freeList(struct sll *head)
{
    while (head != NULL)
    {
        struct sll *nextNode = head->next;
        free(head);
        head = nextNode;
    }
}

