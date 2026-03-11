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

void DFSTrav(int adj[MAX][MAX], int n)
{
    stack s1;
    init(&s1);

    int visited[MAX] = {0}; // init 0 and set 1 for visited

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            visited[i] = 1;
            push(&s1, i);

            while (!isEmpty(&s1))
            {
                int u = pop(&s1);
                printf("%d ", u);

                for (int v = 0; v < n; v++)
                {
                    if (adj[u][v] == 1 && !visited[v])
                    {
                        visited[v] = 1;
                        push(&s1, v);
                    }
                }
            }
        }
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