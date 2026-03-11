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

// --- Utility funtion --- BFS from vertex start
void BFS_from_vertex(int adj[MAX][MAX], int n, int start, int visited[MAX])
{
    queue q1;
    init(&q1);

    visited[start] = 1;
    insertQ(&q1, start);

    while (!isEmpty(&q1))
    {
        int curr = delQ(&q1);
        printf("%d ", curr); // "%c", 'A' + curr -- to display characters instead of numbers 
        // curr->neighb
        for (int neighb = 0; neighb < n; neighb++)
        {
            // if edge exists and outdegree neigh not neighisited
            if (adj[curr][neighb] == 1 && !visited[neighb])
            {
                visited[neighb] = 1;
                insertQ(&q1, neighb);
            }
        }
    }
}

void BFSTrav(int adj[MAX][MAX], int n)
{
    int visited[MAX] = {0}; // init 0 and set 1 for visited

    // check if all vertix visited thorugh the start vertex if not consider another vertix
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            // function call to trav through i as a start
            BFS_from_vertex(adj, n, i, visited);
    }
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
    BFSTrav(adj, n);

    return 0;
}

/* 
* Reverse neighbor loop if you want deterministic order similar to recursive DFS:
-> for (int v = n - 1; v >= 0; v--) (draw the diagram and trav to understand this)
*/