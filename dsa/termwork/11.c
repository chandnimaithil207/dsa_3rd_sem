#include <stdio.h>
#include <stdlib.h>

typedef struct Edge
{
    int src, dest, weight;
} Edge;
typedef struct Subset
{
    int parent;
    int rank;
} Subset;

int find(Subset subsets[], int i);
void Union(Subset subsets[], int x, int y);
int compareEdges(const void *a, const void *b);
void kruskalMST(Edge edges[], int V, int E);

int main()
{
    int V, E;

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &V);

    printf("Enter the number of edges in the graph: ");
    scanf("%d", &E);

    Edge edges[E];

    printf("Enter the edges (source, destination, weight):\n");
    for (int i = 0; i < E; i++)
    {
        printf("Edge %d: ", i + 1);
        scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight);
    }

    kruskalMST(edges, V, E);

    return 0;
}

int find(Subset subsets[], int i)
{
    if (subsets[i].parent != i)
    {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

void Union(Subset subsets[], int x, int y)
{
    int rootX = find(subsets, x);
    int rootY = find(subsets, y);

    if (subsets[rootX].rank < subsets[rootY].rank)
    {
        subsets[rootX].parent = rootY;
    }
    else if (subsets[rootX].rank > subsets[rootY].rank)
    {
        subsets[rootY].parent = rootX;
    }
    else
    {
        subsets[rootY].parent = rootX;
        subsets[rootX].rank++;
    }
}

int compareEdges(const void *a, const void *b)
{
    Edge *edgeA = (Edge *)a;
    Edge *edgeB = (Edge *)b;
    return edgeA->weight - edgeB->weight;
}

void kruskalMST(Edge edges[], int V, int E)
{
    Edge result[V];
    int e = 0;
    int i = 0;

    qsort(edges, E, sizeof(edges[0]), compareEdges);

    Subset subsets[V];
    for (int v = 0; v < V; v++)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    while (e < V - 1 && i < E)
    {
        Edge nextEdge = edges[i++];
        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);

        if (x != y)
        {
            result[e++] = nextEdge;
            Union(subsets, x, y);
        }
    }

    printf("Edges in the Minimal Spanning Tree:\n");
    int totalWeight = 0;
    for (i = 0; i < e; i++)
    {
        printf("Edge %d-%d with weight %d\n", result[i].src, result[i].dest, result[i].weight);
        totalWeight += result[i].weight;
    }
    printf("Total weight of the Minimal Spanning Tree: %d\n", totalWeight);
}
