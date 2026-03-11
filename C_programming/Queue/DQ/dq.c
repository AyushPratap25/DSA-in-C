// machine 

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct
{
    int arr[MAX];
    int front;
    int rear;
} Deque;

// Function prototypes
void initDeque(Deque *dq);
int  isEmpty(Deque *dq);
int  isFull(Deque *dq);

void insertFront(Deque *dq, int item);
void insertRear(Deque *dq, int item);
int  deleteFront(Deque *dq, int *delitem);
int  deleteRear(Deque *dq, int *delitem);
void display(Deque *dq);

// ---------------- Core Functions ----------------

void initDeque(Deque *dq)
{
    dq->front = dq->rear = -1;
}

int isEmpty(Deque *dq)
{
    return (dq->front == -1);
}

int isFull(Deque *dq)
{
    return ((dq->front == 0 && dq->rear == MAX - 1) ||
            (dq->front == dq->rear + 1));
}

void insertFront(Deque *dq, int item)
{
    if (isFull(dq))
    {
        printf("Deque is FULL (insertFront failed)\n");
        return;
    }

    if (dq->front == -1)    // first element
    {
        dq->front = dq->rear = 0;
    }
    else
    {
        dq->front = (dq->front - 1 + MAX) % MAX;
    }

    dq->arr[dq->front] = item;
}

void insertRear(Deque *dq, int item)
{
    if (isFull(dq))
    {
        printf("Deque is FULL (insertRear failed)\n");
        return;
    }

    if (dq->rear == -1)     // first element
    {
        dq->front = dq->rear = 0;
    }
    else
    {
        dq->rear = (dq->rear + 1) % MAX;
    }

    dq->arr[dq->rear] = item;
}

int deleteFront(Deque *dq, int *delitem)
{
    if (isEmpty(dq))
    {
        printf("Deque is EMPTY (deleteFront failed)\n");
        return 0;
    }

    if (delitem)
        *delitem = dq->arr[dq->front];

    if (dq->front == dq->rear)   // only one element
    {
        dq->front = dq->rear = -1;
    }
    else
    {
        dq->front = (dq->front + 1) % MAX;
    }

    return 1;
}

int deleteRear(Deque *dq, int *delitem)
{
    if (isEmpty(dq))
    {
        printf("Deque is EMPTY (deleteRear failed)\n");
        return 0;
    }

    if (delitem)
        *delitem = dq->arr[dq->rear];

    if (dq->front == dq->rear)   // only one element
    {
        dq->front = dq->rear = -1;
    }
    else
    {
        dq->rear = (dq->rear - 1 + MAX) % MAX;
    }

    return 1;
}

void display(Deque *dq)
{
    if (isEmpty(dq))
    {
        printf("Deque is EMPTY\n");
        return;
    }

    printf("Deque: ");
    int i = dq->front;
    while (1)
    {
        printf("%d ", dq->arr[i]);
        if (i == dq->rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

// ---------------- Sample main ----------------

int main()
{
    Deque dq;
    int x;

    initDeque(&dq);

    insertRear(&dq, 10);
    insertRear(&dq, 20);
    insertFront(&dq, 5);
    insertFront(&dq, 1);
    display(&dq);

    deleteFront(&dq, &x);
    printf("Deleted from front: %d\n", x);
    display(&dq);

    deleteRear(&dq, &x);
    printf("Deleted from rear: %d\n", x);
    display(&dq);

    return 0;
}
