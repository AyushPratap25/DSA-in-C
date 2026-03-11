// Program is kept simple, more 2-3 conditions can be checked! for node exists in add edge and so...
#include <stdio.h>
#define MAX 100

// Matrix initilisation
void initMatrix(int adj[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;
}

// Add edge
void addEdge(int adj[MAX][MAX], int u, int v, int graph_type, int n)
{
    if (u >= n || v >= n || u < 0 || v < 0)
    {
        printf("Invalid input!!\n");
        return;
    }
    // can also check if edge already exists!
    adj[u][v] = 1;
    if (graph_type == 1) // undirected
        adj[v][u] = 1;   // symmetric
}

// Delete edge
void delEdge(int adj[MAX][MAX], int u, int v, int graph_type, int n)
{
    if (u >= n || v >= n || u < 0 || v < 0)
    {
        printf("Invalid input!!\n");
        return;
    }
    adj[u][v] = 0;
    if (graph_type == 1) // undirected
        adj[v][u] = 0;
}

// Build Graph
void buildGraph(int adj[MAX][MAX], int n, int graph_type)
{
    int max_edge;
    if (graph_type == 1)
        max_edge = n * (n - 1) / 2; // undirected
    else
        max_edge = n * (n - 1); // directed

    int origin, destin;
    for (int i = 0; i < max_edge; i++) // runs for total no. of edges possible for n vertices
    {
        printf("Enter edge %d org, dest(-1 -1 to quit): ", i + 1);
        scanf("%d %d", &origin, &destin);

        // invalid input check
        if (origin == -1 && destin == -1)
            break;
        // if (origin >= n || destin >= n || origin < 0 || destin < 0) // matrix 0 to n-1
        // {
        //     printf("Invalid input!\nTry again!\n");
        //     i--; // another chance!
        // }
        addEdge(adj, origin, destin, graph_type, n);
    }
}

// Display matrix
void display(int arr[MAX][MAX], int n)
{ // row, col
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

// main
int main()
{
    int adj[MAX][MAX];
    int n;
    int graph_type;

    printf("Enter 1 for undirected & 2 for directed graph: ");
    scanf("%d", &graph_type);

    printf("Enter no. of vertics: ");
    scanf("%d", &n);

    initMatrix(adj, n);
    buildGraph(adj, n, graph_type);

    printf("Before Deletion: \n");
    display(adj, n);

    delEdge(adj, 0, 1, graph_type, n);

    printf("After Deletion: \n");
    display(adj, n);

    return 0;
}