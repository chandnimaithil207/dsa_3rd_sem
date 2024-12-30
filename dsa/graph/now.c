 
#include<stdio.h>
#include<stdlib.h>
#define max 10
typedef struct node
{
    int v;
    struct node*next;
}node;
 //Array of pointers representing adjacency list
node* n[10];

void initialisenode(int ver)
{
    for(int i=0;i<ver;i++)
    {
        n[i]=NULL;             //initially no edges,so set all pointers to NULL
    }
}

void addEdges(int src,int dest)
{
    node *p=NULL;
    p=(node*)malloc(sizeof(node));
    p->v=dest;
    p->next=NULL;
    if(n[src]==NULL)
    {
        n[src]=p;       
    }
    else
    {
        node *temp=NULL;
        temp=n[src];
        while(temp->next!=NULL)
        temp=temp->next;

        temp->next=p;
    }
}

void printGraph(int ver)
{
    for(int i=0;i<ver;i++)
    {
        printf("For vertex %d",i);
        node *t=n[i];
        if(t==NULL)
        printf("No edge \n");
        else
        {
            while(t!=NULL)
            {
                printf("->%d ",t->v);
                t=t->next;
            }
            printf("\n");
        }   
    }
}
int main()
{
    int ver,src,dest,edg;

    printf("Enter no. of vertices");
    scanf("%d",&ver);

    printf("\nEneter the no. of edges");
    scanf("%d",&edg);

    initialisenode(ver);

    for(int i=0;i<edg;i++)
    {
        printf("Enter edge info (src dest weight) %d",i+1);
        scanf("%d %d",&src,&dest);
        addEdges(src,dest);
    }

    printf("Graph representation\n");
    printGraph(ver);

}