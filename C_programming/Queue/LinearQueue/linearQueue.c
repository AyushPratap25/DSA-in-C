#include <stdio.h>
#define MAX 10

// queue structure
typedef struct 
{
    int arr[MAX];
    int front;
    int rear;
} queue;

// queue init
void init(queue *q)
{
    q->front = q->rear = -1;
}

// empty 
int isEmpty(queue *q)
{
    return (q->front == -1);
}

// full 
int isFull(queue *q)
{
    return (q->rear == MAX - 1);
}

// insert item
void insertQ(queue *q, int item)
{
    if (isFull(q)) 
    {
        printf("Queue is Full!\n");
        return;
    }

    if (q->front == -1)
        q->front = 0;
    q->arr[++(q->rear)] = item;
}

// delete item
void delQ(queue *q, int *delitem)
{
    if (isEmpty(q))
    {
        printf("Queue is Empty!\n");
        return;
    }

    if (delitem) // not NULL
        *delitem = q->arr[(q->front)];  // move front ahead +1

    if (q->front == q->rear)
        q->front = q->rear = -1;
    else 
        q->front++;
}

void display(queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty!\n");
        return;
    }
    for (int i = q->front; i <= q->rear; i++)
        printf("%d ", q->arr[i]);
    printf("\n");
}

int main()
{
    queue q;
    init(&q);

    insertQ(&q, 25);
    insertQ(&q, 12);
    insertQ(&q, 32);
    insertQ(&q, 42);

    delQ(&q, NULL);
    display(&q);

    return 0;
}

