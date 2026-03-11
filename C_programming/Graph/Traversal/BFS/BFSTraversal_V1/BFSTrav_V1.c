// BFS from a vertex "start" -> Traverses the connected component using a queue
#include <stdio.h>
#define MAX 10

#pragma region Queue
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
    // here the 2nd cond. is not required since we are reseting front && rear as -1
    return (q->rear == -1 || q->front > q->rear);
}

int isFull(queue *q)
{
    return (q->rear == MAX - 1);
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
    q->arr[++(q->rear)] = item;
}

int delQ(queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty!\n");
        return -1; // error code , note not to give +ve int as it might represent the vertix
    }

    int delitem = q->arr[(q->front)++];
    if (q->front > q->rear)
        q->front = q->rear = -1; // reset

    return (delitem);
}

#pragma endregion

void BFS(int adj[MAX][MAX], int n)
{
    // queue
    queue q1;
    init(&q1);

    int visited[MAX] = {0}; // init 0 and set 1 for visited

    for (int i = 0; i < n; i++)
    {
        if (!visited[i]) // checks for all if visited, efficient
        {
            visited[i] = 1;
            insertQ(&q1, i);
            while (!isEmpty(&q1))
            {
                int u = delQ(&q1);
                printf("%d ", u);

                for (int v = 0; v < n; v++)
                {
                    if (adj[u][v] == 1 && !visited[v])
                    {
                        visited[v] = 1;
                        insertQ(&q1, v);
                    }
                }
            }
        }
    }
    printf("\n");
}

int main()
{
    int n = 4;
    int adj[MAX][MAX] = {
        {0, 1, 0, 0},
        {0, 0, 0, 1},
        {0, 1, 0, 0},
        {1, 0, 1, 0}};

    // function call
    BFS(adj, n);

    return 0;
}