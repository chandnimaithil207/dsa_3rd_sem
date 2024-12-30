#include<stdio.h>
#define max 5
int push1(int [],int ,int);
int push2(int [],int ,int);
int pop1(int [],int );
int pop2(int [],int );
void disp(int [],int ,int);
int main()
{
   int stack[max], top1 = -1,top2=max;
   int ch;
   do
   {
      printf("\n1-push1\n2-push2\n3pop1-\n4-pop2\n5-display\n");
      scanf("%d", &ch);
      switch (ch)
      {
        case 1:
        printf("enter the first stack\n");
        top1 = push1(stack,top1,top2);
        break;
        case 2:
        printf("enter the second stack\n");
        top2 = push2(stack,top1,top2);
        break;   
        case 3:
        top1=pop1(stack, top1);
        break;
        case 4:
        top2=pop2(stack,top2);
        break;
        case 5:
        disp(stack,top1,top2);
        default:
        printf("invalid choice---");
        break;
      }
   } while (ch>=1 && ch <= 5);
   return 0;
}

int push1(int stack[],int t1,int t2)
{
    int x;
    if(t1==t2-1||t2==-1)
    {
       printf("stack overflow");
    }
    else
    {
        scanf("%d",&x);
        t1++;
        stack[t1]=x;
    }
    return t1;
}
int push2(int stack[],int t1,int t2)
{
    int x;
    if(t1==t2-1||t2==-1)
    {
       printf("stack overflow");
    }
    else
    {
        scanf("%d",&x);
        t2--;
        stack[t2]=x;
    }
    return t2; 
}

int pop1(int stack[],int t1)
{
    if(t1==-1)
    printf("stack is empty");
    else
    {
        printf("popped element -%d ",stack[t1]);
        t1--;
        
    }
    return t1;
}
int pop2(int stack[],int t2)
{
    if(t2==max)
    printf("stack is empty");
    else
    {
        printf("popped element -%d ",stack[t2]);
        t2++;
        
    }
    
    return t2;
}

void disp(int stack[],int t1,int t2)
{
    if(t1==-1 && t2==max)
    printf("both are empty stack");
    else
    for(int i=0;i<=t1;i++)
    printf("%d ",stack[i]);
    printf("\n");
    for(int i=max-1;i>=t2;i--)
    printf("%d",stack[i]);
}
