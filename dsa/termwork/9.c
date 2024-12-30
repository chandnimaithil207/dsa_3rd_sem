
//Q9. Write a C program to store the details of a weighted graph.///

#include <stdio.h>
#include <stdlib.h>

// Define the structure for graph nodes (with doubly linked list for adjacency)
struct Node
{
    int vertex;
    int weight;
    struct Node* next;
    struct Node* prev;  // For doubly linked list (optional)
};

// Array of pointers representing the adjacency list
struct Node* node[10]; // Assuming 3 vertices

// Function to initialize the graph nodes
void initializeNodes(int size)
{
    for (int i = 0; i < size; i++)
    {
        node[i] = NULL;  // Initially, no edges, so set all pointers to NULL
    }
}

// Function to add an edge to the graph
void addEdge(int src, int dest, int weight)
{
    // Create new node for the src -> dest edge
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->vertex = dest;
    newNode->weight = weight;
    newNode->next = NULL;  // No next node initially
    newNode->prev = NULL;  // No previous node initially

    // Insert the new node at the end of the adjacency list for src
    if (node[src] == NULL)
    {
        node[src] = newNode;  // If no edges, add the first edge
    }
    else
    {
        struct Node* temp = node[src];
        // Traverse to the end of the list
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;  // Add the new node at the end
        newNode->prev = temp;  // Set the previous pointer of the new node
    }
}

// Function to print the graph
void printGraph(int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Vertex %d: ", i);
        struct Node* temp = node[i];
        if (temp == NULL)
        {
            printf("No edges\n");  // If there are no edges for this vertex
        }
        else
        {
            while (temp)
            {
                printf("-> %d (weight %d) ", temp->vertex, temp->weight);
                temp = temp->next;
            }
            printf("\n");
        }
    }
}

int main()
{
    int vertices; // Number of vertices
    int edges, src, dest, weight;
    printf("\t\t\t\t\t\t\t*******OUTPUT********\t\t\t\t\n");
    printf("enter vertices:");
    scanf("%d",&vertices);
    // Initialize graph nodes
    initializeNodes(vertices);

    
    // for(int i=0;i<vertices;i++)
    // {
    //     printf("enter edges for vertice %d--\n",i);
    // Ask the user for the number of edges
    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    // Add edges to the graph based on user input
    for (int i = 0; i < edges; i++)
    {
        printf("Enter edge %d (source destination weight): ", i + 1);
        scanf("%d %d %d", &src, &dest, &weight);
     addEdge(src, dest, weight);

    }
    // }
    // Print the graph after adding edges
    printf("\nGraph Representation:\n");
    printGraph(vertices);

    return 0;
}



// #include <stdio.h>
// #include <stdlib.h>

// #define MAX 100

// void adjmat(int vertices, int edges);
// void edgeList(int vertices, int edges);

// int main()
// {
//     int vertices, edges, choice;

//     printf("Enter the number of vertices: ");
//     scanf("%d", &vertices);

//     printf("Enter the number of edges: ");
//     scanf("%d", &edges);

//     while (1)
//     {
//         printf("\nMenu:\n");
//         printf("1. Store graph using Adjacency Matrix\n");
//         printf("2. Store graph using Edge List\n");
//         printf("3. Exit\n");
//         printf("Enter your choice: ");
//         scanf("%d", &choice);

//         switch (choice)
//         {
//         case 1:
//             adjmat(vertices, edges);
//             break;
//         case 2:
//             edgeList(vertices, edges);
//             break;
//         case 3:
//             printf("Exiting program.\n");
//             exit(0);
//         default:
//             printf("Invalid choice! Please try again.\n");
//         }
//     }

//     return 0;
// }

// void adjmat(int vertices, int edges)
// {
//     int adjMatrix[MAX][MAX] = {0};
//     int src, dest, weight;

//     printf("Enter the edges with weights (source destination weight):\n");
//     for (int i = 0; i < edges; i++)
//     {
//         scanf("%d %d %d", &src, &dest, &weight);

//         if (src < 0 || src >= vertices || dest < 0 || dest >= vertices)
//         {
//             printf("Invalid edge! Vertices should be between 0 and %d.\n", vertices - 1);
//             i--;
//             continue;
//         }

//         adjMatrix[src][dest] = weight;
//         adjMatrix[dest][src] = weight; // For undirected graph
//     }

//     printf("\nAdjacency Matrix:\n");
//     for (int i = 0; i < vertices; i++)
//     {
//         for (int j = 0; j < vertices; j++)
//         {
//             printf("%d ", adjMatrix[i][j]);
//         }
//         printf("\n");
//     }
// }

// void edgeList(int vertices, int edges)
// {
//     struct Edge
//     {
//         int src, dest, weight;
//     } edgeList[MAX];

//     printf("Enter the edges with weights (source destination weight):\n");
//     for (int i = 0; i < edges; i++)
//     {
//         scanf("%d %d %d", &edgeList[i].src, &edgeList[i].dest, &edgeList[i].weight);

//         if (edgeList[i].src < 0 || edgeList[i].src >= vertices ||
//             edgeList[i].dest < 0 || edgeList[i].dest >= vertices)
//         {
//             printf("Invalid edge! Vertices should be between 0 and %d.\n", vertices - 1);
//             i--;
//             continue;
//         }
//     }
//     // Display the Edge List
//     printf("\nEdge List:\n");
//     for (int i = 0; i < edges; i++)
//     {
//         printf("Edge %d: src=%d, dest=%d, weight=%d\n", i + 1, edgeList[i].src, edgeList[i].dest, edgeList[i].weight);
//     }
// }