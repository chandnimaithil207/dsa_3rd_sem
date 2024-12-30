#include<stdio.h>
#define max 10
int penq(int [],int,int *);
void pdeq(int [],int * );
void disp(int [],int *);
int main()                       //priority queue using array------------------
{
    int pq[max],ch,r=0,c=0;
    do
    {
        printf("enter menu\n1-enqueue\n2-dequeue\n3-display\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            r=penq(pq,r,&c);
            break;
            case 2:
            pdeq(pq,&r);
            break;
            case 3:
            disp(pq,&c);
            break;
        }
    } while (ch<=3);
    return 0;
}

int penq(int pq[],int r,int *c)
{
    int p,v;
    if(r>=max-1)
    {
        printf("queue overflow");
    }
    else
    {
        printf("enter the priority and value---\n");
        scanf("%d%d",&p,&v);
        pq[r]=p;
        pq[r+1]=v;
        r+=2;
        *c=*c+2;
    }
    return r;
}

void pdeq(int pq[],int *r)
{
    int min,i,j;
    if(*r<=0)
    printf("queue underflow");
    else
    {
        min=pq[0];
        for(i=2;i<*r-1;i++)
        {
          if(min>pq[i])
          {
             min=pq[i];
             j=i;
          }
        }
        printf("value of the highest priority----%d",pq[j+1]);
        pq[j]=999;
        *r-=2;
    }
}

void disp(int pq[],int *c)
{
    if(*c==-1)
    printf("queue underflow");
    else
    for(int i=1;i<=(*c);i+=2)
    printf("%d  ",pq[i]);
}





























































// #include <stdio.h>
// #define max 10
// int pqenq(int [],int );
// void pqdeq(int [],int* );
// int main()
// {
//     int pq[max],r=0,ch;
//     do{
//         printf("\nMenu\n1.Enque\n2.Deque\n");
//         printf("Enter choice:");
//         scanf("%d",&ch);
//         switch(ch)
//         {
//             case 1:
//                     r=pqenq(pq,r);
//                     break;
//             case 2:
//                     pqdeq(pq,&r);
//                     break;
//         }
//     }while(ch<=2);

//     return 0;
// }

// int pqenq(int pq[],int r)
// {
//     int p,d;
//     if(r>=max-1)
//     {
//         printf("Queue is full");
//     }
//     else
//     {
//         printf("Enter priority and data:");
//         scanf("%d%d",&p,&d);
//         pq[r]=p;
//         pq[r+1]=d;
//         r=r+2;
//     }
//     return r;
// }

// void pqdeq(int pq[],int *r)
// {
//     int i,j=0,x,min;
//     if(*r==0)
//     {
//         printf("queue is empty");
//         return;
//     }
//     min=pq[0];
//     for(i=2;i<(*r)-1;i+=2)
//     {
//         if(min>pq[i])
//         {
//             min=pq[i];
//             j=i;
//         }
//     }
//     printf("priority value:%d",pq[j+1]);
//     pq[j]=999;
//     *r-=2;
// }