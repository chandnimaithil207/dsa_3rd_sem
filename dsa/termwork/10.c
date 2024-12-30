#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct Queue
{
    int items[MAX];
    int front, rear;
} Queue;

typedef struct Graph
{
    int vertices;
    int adjMatrix[MAX][MAX];
} Graph;

void initGraph(Graph *graph, int vertices);
void addEdge(Graph *graph, int src, int dest);
void printGraph(Graph *graph);
void dfs(Graph *graph, int start, int visited[]);
void bfs(Graph *graph, int start);

Queue *createQueue();
void enqueue(Queue *q, int value);
int dequeue(Queue *q);
int isEmpty(Queue *q);

int main()
{
    int vertices, edges, choice, src, dest, start;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    Graph graph;
    initGraph(&graph, vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (source destination):\n");
    for (int i = 0; i < edges; i++)
    {
        scanf("%d %d", &src, &dest);
        addEdge(&graph, src, dest);
    }

    printf("\nGraph representation (Adjacency Matrix):\n");
    printGraph(&graph);

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Depth First Search (DFS)\n");
        printf("2. Breadth First Search (BFS)\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the starting vertex for DFS: ");
            scanf("%d", &start);
            int visited[MAX] = {0};
            printf("DFS Traversal: ");
            dfs(&graph, start, visited);
            printf("\n");
            break;
        case 2:
            printf("Enter the starting vertex for BFS: ");
            scanf("%d", &start);
            printf("BFS Traversal: ");
            bfs(&graph, start);
            printf("\n");
            break;
        case 3:
            printf("Exiting program.\n");
            exit(0);
        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

void initGraph(Graph *graph, int vertices)
{
    graph->vertices = vertices;
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            graph->adjMatrix[i][j] = 0;
        }
    }
}

void addEdge(Graph *graph, int src, int dest)
{
    graph->adjMatrix[src][dest] = 1;
    graph->adjMatrix[dest][src] = 1;
}
void printGraph(Graph *graph)
{
    for (int i = 0; i < graph->vertices; i++)
    {
        for (int j = 0; j < graph->vertices; j++)
        {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// Depth First Search (DFS)
void dfs(Graph *graph, int start, int visited[])
{
    visited[start] = 1;
    printf("%d ", start);

    for (int i = 0; i < graph->vertices; i++)
    {
        if (graph->adjMatrix[start][i] && !visited[i])
        {
            dfs(graph, i, visited);
        }
    }
}

// Breadth First Search (BFS)
void bfs(Graph *graph, int start)
{
    int visited[MAX] = {0};
    Queue *q = createQueue();

    visited[start] = 1;
    enqueue(q, start);

    while (!isEmpty(q))
    {
        int current = dequeue(q);
        printf("%d ", current);

        for (int i = 0; i < graph->vertices; i++)
        {
            if (graph->adjMatrix[current][i] && !visited[i])
            {
                visited[i] = 1;
                enqueue(q, i);
            }
        }
    }
}

// Queue functions for BFS
Queue *createQueue()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

void enqueue(Queue *q, int value)
{
    if (q->rear == MAX - 1)
    {
        printf("Queue overflow\n");
        return;
    }
    if (q->front == -1)
    {
        q->front = 0;
    }
    q->items[++q->rear] = value;
}

int dequeue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue underflow\n");
        return -1;
    }
    int value = q->items[q->front++];
    if (q->front > q->rear)
    {
        q->front = q->rear = -1;
    }
    return value;
}

int isEmpty(Queue *q)
{
    return q->front == -1;
}
