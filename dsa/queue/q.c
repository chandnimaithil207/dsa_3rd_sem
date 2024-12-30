#include<stdio.h>
#define max 5
int enqueue(int [],int,int);
int dequeue(int [],int,int);
void disp(int [],int,int);
void peek(int [],int);
int main()                                // simple queue------------
{
    int ch,q[max],r=-1,f=-1;
    do
    {
        printf("MAIN MENU-----\n1-enqueue\n2-dequeue\n3-display\n4-peek\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                r=enqueue(q,f,r);
                if(f==-1)
                f=0;
                break;
            case 2:
                f=dequeue(q,f,r);
                if(f==-1)
                r=-1;
                break;
            case 3:
                disp(q,f,r);
                break;
            case 4:
                peek(q,f);
                break;
            default:
                break;
        }
    } while (ch>=1 && ch<=4);
    
    return 0;
}

int enqueue(int q[],int f,int r)
{
    int x;
    if(r==max-1 && f==max-1)
    {
        printf("queue overflow");
    }
    else
    {
        printf("enter the element--");
        scanf("%d",&x);
        r++;
        q[r]=x;
    }
    return r;
    
}


int dequeue(int q[],int f,int r)
{
    int x;
    if(r==-1 && f==-1)
    {
        printf("queue empty");
    }
    else
    {
        x=q[f];
        printf("%d",x);
        if(f==r)
        f=-1;
        else
        f++;
    }
    return f;
    
}

void disp(int q[],int f,int r)
{
    if(f==-1 && r==-1)
    {
        printf("empty queue");
    }
    else
    {
        while(f!=r)
        {
            printf("%d",q[f]);
            f++;
        }
    }
}

void peek(int q[],int f)
{
    if(f==-1)
    {
        printf("empty queue0");
    }
    else
    printf("%d",q[f]);
}