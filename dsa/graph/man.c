#include <stdio.h>
#include <stdlib.h>

// Node structure for adjacency list
typedef struct Node 
{
    int vertex;
    struct Node* next;
} Node;

// Function prototypes
Node* createNode(int vertex);
void addEdge(Node* graph[], int u, int v);
void dfs(int n, Node* graph[], int visited[], int start, int end);
void bfs(int n, Node* graph[], int start, int end);

int main() {
    int n, edges, u, v, start, end;

    // Input number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    // Create adjacency list
    Node* graph[n];
    for (int i = 0; i < n; i++) {
        graph[i] = NULL; // Initialize each list as empty
    }

    // Input edges for each vertex
    for (int i = 0; i < n; i++) {
        printf("Enter the number of edges for vertex %d: ", i);
        scanf("%d", &edges);
        printf("Enter the edges (connected vertices) for vertex %d:\n", i);
        for (int j = 0; j < edges; j++) {
            scanf("%d", &v);
            addEdge(graph, i, v); // Add edge i to v
        }
    }

    // Input starting vertex and end vertex
    printf("Enter the starting vertex: ");
    scanf("%d", &start);
    printf("Enter the end vertex: ");
    scanf("%d", &end);

    // Perform DFS
    int visited[n];
    for (int i = 0; i < n; i++) visited[i] = 0; // Initialize visited array

    printf("DFS Traversal from %d to %d: ", start, end);
    dfs(n, graph, visited, start, end);
    printf("\n");

    // Perform BFS
    printf("BFS Traversal from %d to %d: ", start, end);
    bfs(n, graph, start, end);
    printf("\n");

    return 0;
}

// Function to create a new node
Node* createNode(int vertex) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Function to add an edge to the adjacency list
void addEdge(Node* graph[], int u, int v) {
    Node* newNode = createNode(v);

    // If the list is empty, insert the new node at the start
    if (graph[u] == NULL) {
        graph[u] = newNode;
    } else {
        // Traverse to the end of the list
        Node* temp = graph[u];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        // Add the new node at the end of the list
        temp->next = newNode;
    }
}

// DFS function
void dfs(int n, Node* graph[], int visited[], int start, int end) {
    // Print the current vertex
    printf("%d ", start);
    visited[start] = 1;

    // Check if the end vertex is reached
    if (start == end) {
        return;
    }

    Node* temp = graph[start];
    while (temp != NULL) {
        if (!visited[temp->vertex]) {
            dfs(n, graph, visited, temp->vertex, end);
            // If we reach the end vertex, we can stop the recursion
            if (visited[end]) {
                return;
            }
        }
        temp = temp->next;
    }
}

// BFS function
void bfs(int n, Node* graph[], int start, int end) {
    int queue[n], front = 0, rear = 0;
    int visited[n];
    for (int i = 0; i < n; i++) visited[i] = 0; // Initialize visited array

    // Enqueue the starting vertex and mark as visited
    queue[rear++] = start;
    visited[start] = 1;

    while (front < rear) {
        int curr = queue[front++];
        printf("%d ", curr);

        // Check if the end vertex is reached
        if (curr == end) {
            return;
        }

        // Enqueue all unvisited neighbors
        Node* temp = graph[curr];
        while (temp != NULL) {
            if (!visited[temp->vertex]) {
                queue[rear++] = temp->vertex;
                visited[temp->vertex] = 1;
            }
            temp = temp->next;
        }
    }
}
