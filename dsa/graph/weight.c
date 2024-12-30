#include<stdio.h>
#include<stdlib.h>
#define max 10
typedef struct node
{
    int v;
    int w;
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

void addEdges(int src,int dest,int wt)
{
    node *p=NULL;
    p=(node*)malloc(sizeof(node));
    p->v=dest;
    p->w=wt;
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
                printf("->%d (weight %d) ",t->v,t->w);
                t=t->next;
            }
            printf("\n");
        }   
    }
}
int main()
{
    int ver,src,dest,wt,edg;

    printf("Enter no. of vertices");
    scanf("%d",&ver);

    initialisenode(ver);

    printf("\nEneter the no. of edges");
    scanf("%d",&edg);

    for(int i=0;i<edg;i++)
    {
        printf("Enter edge info (src dest weight) %d",i+1);
        scanf("%d %d %d",&src,&dest,&wt);
        addEdges(src,dest,wt);
    }

    printf("Graph representation\n");
    printGraph(ver);

}


// #include<stdio.h>
// #include<stdlib.h>
// #define max 3
// void addnode(int,int);
// void printList();
// typedef struct node
// {
//     int v;
//     struct node *next;
// }n;
// typedef struct list
// {
//     struct list*head;
// }l;
// l *adjlist[max]={0};
// void main()
// {
//     int i ;
//     for(i=0;i<max;i++)
//     {
//         adjlist[i]=(l*)malloc(sizeof(l));
//         adjlist[i]->head=NULL;
//     }
//     addnode(0,1);
//     addnode(0,3);
//     addnode(1,2);
//     printList();
// }

// void addnode(int s,int d)
// {
//     n*dest,*temp,*src;
//     if(adjlist[s]->head==NULL)
//     {
//         src=(n*)malloc(sizeof(n));
//         src->v=s;
//         src->next=NULL;
//         adjlist[s]->head=src;
//     }
//     dest=(n*)malloc(sizeof(n));
//     dest->v=d;
//     dest->next=NULL;
//     temp=adjlist[s]->head;
//     while(temp->next!=NULL)
//     temp=temp->next;
//     temp->next=dest;
    
// }

// void printList()
// {
//     int i;
//     for(i=0;i<max;++i)
//     {
//         n *p=adjlist[i]->head;
//         printf("Adjancency list for vertex : %d\n",i);
//         while(p)
//         {
//             printf("%d ",p->v);
//             p=p->next;
//         }
//         printf("\n");
//     }
// }

