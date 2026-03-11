// Circular Queue
#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct
{
    int arr[MAX];
    int front;
    int rear;
} queue;

void init(queue *q)
{
    q->front = q->rear = -1;
}

int isEmpty(queue *q)
{
    return (q->front == -1);
}

int isFull(queue *q)
{
    return ((q->front == 0 && q->rear == MAX - 1) || (q->front == q->rear + 1));
}

void insertQ(queue *q, int item)
{
    if (isFull(q))
    {
        printf("Queue is full!\n");
        return;
    }

    if (q->front == -1)
        q->front = 0;

    q->rear = (q->rear + 1) % MAX;
    q->arr[q->rear] = item;
}

int delQ(queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty!\n");
        return 0; // error code
    }

    int delitem = q->arr[q->front];

    if (q->front == q->rear)
        q->front = q->rear = -1; // reset
    else
        q->front = (q->front + 1) % MAX;

    return delitem;
}

void display(queue *q)
{
    if (isEmpty(q))
    {
        printf("Empty!\n");
        return;
    }

    for (int i = q->front; i != q->rear; i = (i + 1) % MAX)
    {
        printf("%d ", q->arr[i]);
    }
    printf("%d\n", q->arr[q->rear]);
}

int main()
{
    queue q1;
    init(&q1);

    display(&q1);

    insertQ(&q1, 12);
    insertQ(&q1, 3);
    insertQ(&q1, 7);
    // delQ(&q1);
    insertQ(&q1, 7);
    insertQ(&q1, 7);
    insertQ(&q1, 9);

    display(&q1);

    // delQ(&q1);
    // delQ(&q1);

    // display(&q1);

    return 0;
}