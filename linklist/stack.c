#include<stdio.h>
#include<stdlib.h>
typedef struct stack
{
    int data;
    struct stack *next;
}s;
s* push(s*);
s* pop(s*);
void disp(s*);
void peek(s*);
int main()
{
    s *top=NULL;
    int ch;
    do
    {
        printf("enter menu\n1-push\n2-pop\n3-display\n4-peek\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            top=push(top);
            break;
            // case 2:
            // top=pop(top);
            // break;
            case 2:
            disp(top);
            break;
            // case 4:
            // peek(top);
            // break;
            // default:
            // break;
        }
    } while (ch<3);
    return 0;    
}

s* push(s*top)
{
    s* t=NULL;
    t=(s*)malloc(sizeof(s));
    if(t!=NULL)
    {
            printf("enter the element");
            scanf("%d",&t->data);
            t->next=top;
            top=t;
    }
    
    return top;
}

void disp(s* top)
{
    if(top==NULL)
    printf("stack underflow");
    else
    {
        while(top!=NULL)
        {
        printf("%d ",top->data);
        top=top->next;
        }
    }
}
