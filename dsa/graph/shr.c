#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the adjacency list
typedef struct Node
{
    int vertex;
    int weight;
    struct Node *next;
} Node;

// Structure for the adjacency list
typedef struct List
{
    Node *head;
} List;

// Structure for the graph
typedef struct Graph
{
    int vertices;
    List *array;
} Graph;

// Function to create a new node
Node *createNode(int vertex, int weight)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with a given number of vertices
Graph *createGraph(int vertices)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->vertices = vertices;
    graph->array = (List *)malloc(vertices * sizeof(List));

    for (int i = 0; i < vertices; i++)
    {
        graph->array[i].head = NULL;
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph *graph, int src, int dest, int weight)
{
    // Add edge from src to dest
    Node *newNode = createNode(dest, weight);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    // Add edge from dest to src (for undirected graph)
    newNode = createNode(src, weight);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// Function to display the adjacency list of the graph
void printGraph(Graph *graph)
{
    printf("\nGraph adjacency list:\n");
    for (int i = 0; i < graph->vertices; i++)
    {
        printf("Vertex %d --> ", i);
        Node *current = graph->array[i].head;
        while (current)
        {
            printf("(%d, weight: %d),  ", current->vertex, current->weight);
            current = current->next;
        }
        printf("\n");
    }
}

int main()
{
    int vertices, choice;

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &vertices);

    Graph *graph = createGraph(vertices);

    do
    {
        printf("\n--- Menu ---\n");
        printf("1. Add Edge\n");
        printf("2. Print Graph\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            int src, dest, weight;
            printf("Enter source vertex, destination vertex, and weight of the edge: ");
            scanf("%d %d %d", &src, &dest, &weight);

            if (src >= vertices || dest >= vertices || src < 0 || dest < 0)
            {
                printf("Invalid vertices! Please enter values between 0 and %d.\n", vertices - 1);
            }
            else
            {
                addEdge(graph, src, dest, weight);
                printf("Edge added between %d and %d with weight %d.\n", src, dest, weight);
            }
            break;
        }
        case 2:
            printGraph(graph);
            break;
        case 3:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 3);

    // Free the graph memory
    for (int i = 0; i < vertices; i++)
    {
        Node *current = graph->array[i].head;
        while (current)
        {
            Node *temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(graph->array);
    free(graph);

    return 0;
}



//bst


#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct Tnode
{
    struct Tnode *left;
    int data;
    struct Tnode *right;
}tree;

int ln=0,n1=0,n2=0;
tree *insert(tree *root,int n)
{
    
    if(root == NULL)
    {
        tree *temp = (tree *)malloc(sizeof(tree));
        root = temp;
        root->data = n;
        temp->left = NULL;
        temp->right = NULL;
    }
    else
    {
        if(n > root->data)
            root->right = insert(root->right,n);
        else if(n < root->data)
            root->left = insert(root->left,n);
        else
            printf("Equal numbers can't be entered\n");
    }      
    return root;
}
int inordersucc(tree *root)
{
    while(root->left != NULL)
        root = root->left;
    return root->data;
}
tree *del(tree *root,int n)
{
    if(root == NULL)
    {
        printf("Empty Tree or number not found\n");
        return root;
    }

    if(n > root->data)
            root->right = del(root->right,n);
    else if(n < root->data)
            root->left = del(root->left,n); 
    else
    {
        if(root->right == NULL && root->left == NULL)
        {
            free(root);
            return NULL;
        }
        else if(root->right == NULL || root->left == NULL)
        {
            tree *temp = root;
            if(root->right != NULL)
                root = root->right;
            else
                root = root->left;
            free(temp);
            return root;
        }
        else
        {
            int n = inordersucc(root->right);
            root->data = n;
            root->right = del(root->right,n);
        }
    }
    return root;
}
void count(tree *root)
{
    if(root == NULL)
        return;
    else
    {
        if(root->right == NULL && root->left == NULL)
            ln++;
        else if(root->right == NULL || root->left == NULL)
            n1++;
        else if(root->right != NULL && root->left != NULL)
            n2++;
        count(root->left);
        count(root->right);
    }

}
void inorderdisplay(tree *root)
{
    if(root == NULL)
        return;

    inorderdisplay(root->left);
    printf("%d ",root->data);
    inorderdisplay(root->right);
    
}
void postorderdisplay(tree *root)
{
    if(root == NULL)
        return;
    postorderdisplay(root->left);
    postorderdisplay(root->right);
    printf("%d ",root->data);

}
void preorderdisplay(tree *root)
{
    if(root == NULL)
        return;
    printf("%d ",root->data); 
    preorderdisplay(root->left);
    preorderdisplay(root->right);
}

int main()
{
    tree *root = NULL;
    int ch,n;
    do
    {
        printf("Enter the operation ");
        scanf("%d",&ch);
        switch (ch)
        {
            case 1 :    printf("Enter the number ");
                        scanf("%d",&n);
                        root = insert(root,n);
                        break;
            
            case 2 :    printf("Enter the number ");
                        scanf("%d",&n);
                        root = del(root,n);
                        break;
            
            case 3 :    inorderdisplay(root);
                        printf("\n");
                        break;
            
            case 4 :    postorderdisplay(root);
                        printf("\n");
                        break;
            
            case 5 :    preorderdisplay(root);
                        printf("\n");
                        break;
            
            case 6 :    count(root);
                        printf("The count of leaf node is %d\nThe count of node having 1 child is %d\nThe count of node having 2 child is %d\nThe nodes sharing same parents are %d\n",ln,n1,n2,2*n2);
                        break;
        
            default :   exit(0);            
        }
    } while (1);
    
}