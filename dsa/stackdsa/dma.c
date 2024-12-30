#include<stdio.h>
#include<stdlib.h>
#define max 5
void push(int *,int );
void pop(int *,int );
void disp(int *,int );
void peek(int *,int );
int main()
{
    int i,top=-1,*stack=NULL,ch;
    stack=(int*)malloc(max*sizeof(int));
    do
    {
       printf("\n1-push\n2-pop\n3-disp\n4-peek\n5-exit-----\n");
       scanf("%d",&ch);
         switch(ch)
         {
            case 1:
                   push(stack,top);
                   break;
            case 2:
                   pop(stack,top);
                   break;
            case 3:
                  disp(stack,top);
                  break;
            case 4:
                  peek(stack,top);
                  break;
            case 5:
                  break;
            default:
                printf("invalid");

        }
    }while(ch<=4);
    
    
    return 0;
    free(stack);
}

void push(int *stack ,int top)
{
    int x;
    if(top==max-1)
    printf("stackoverflow");
    else
    {
    
       scanf("%d",&x);
       top++;
       stack[top]=x;
   }
}

void pop(int *stack ,int top)
{
    int x;
    if(top==-1)
       printf("empty stack");
    else
    {
       x=stack[top];
       printf("popped elements----");
       printf("%d",x);
       top--;;
    }
   
}

void disp(int *stack,int p)
{
    if(p==-1)
        printf("stack underflow");    
    else
    {
        while((p)!=-1)
        {
           printf("%d",stack[p]);
           (p)--;
        }
    }
}

void peek(int *stack ,int p)
{
    if((p)==-1)
    printf("stack unmderflow");
    else
    printf("%d",stack[p]);
}