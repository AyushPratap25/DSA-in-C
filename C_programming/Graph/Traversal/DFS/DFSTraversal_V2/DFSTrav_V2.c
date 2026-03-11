#include <stdio.h>
#define MAX 10

#pragma region Stack
// stack structure
typedef struct
{
    int arr[MAX];
    int top;
} stack;

void init(stack *s)
{
    s->top = -1;
}

int isEmpty(stack *s)
{
    return (s->top == -1);
}

int isFull(stack *s)
{
    return (s->top == MAX - 1);
}

void push(stack *s, int item)
{
    if (isFull(s))
    {
        printf("\nStack is full!!\n");
        return;
    }
    s->arr[++(s->top)] = item;
}

int pop(stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is Empty!!\n");
        return -1; // error code
    }
    return (s->arr[(s->top)--]);
}
#pragma endregion

//--Utility function -- DFS from vertix start
void DFS_from_vertex(int adj[MAX][MAX], int n, int start, int visited[MAX])
{
    // stack
    stack s1;
    init(&s1);

    visited[start] = 1;
    push(&s1, start);
    // loop through all neighbour
    while (!isEmpty(&s1))
    {
        int curr = pop(&s1);
        printf("%c ", 'A' + curr); // print as character

        for (int neigh = n - 1; neigh >= 0; neigh--)
        {
            if (adj[curr][neigh] == 1 && !visited[neigh])
            {
                visited[neigh] = 1;
                push(&s1, neigh);
            }
        }
    }
}

void DFSTrav(int adj[MAX][MAX], int n)
{
    int visited[MAX] = {0}; // init 0 and set 1 for visited

    // check through all vetex one by one to avoid skipping disconnnected graph vertix trav
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            // function call
            DFS_from_vertex(adj, n, i, visited);
    }
}

int main()
{

    int adj[MAX][MAX] = {
        {0, 1, 1, 0}, // A → B, A → C
        {0, 0, 0, 1}, // B → D
        {0, 0, 0, 1}, // C → D
        {0, 0, 0, 0}  // D → (none)
    };

    DFSTrav(adj, 4);
    return 0;
}