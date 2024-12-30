#include<stdio.h>
#include<stdlib.h>
typedef struct list
{
    int data;
    struct list *next;
}s;
s* push(s*);
s* pop(s*);
void disprec(s*);
int main()
{
    s *top=NULL;
    int ch;
    do
    {
        printf("enter menu\n1-push\n2-pop\n3-display\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            top=push(top);
            break;
            case 2:
            top=pop(top);
            break;
            case 3:
            disprec(top);
            break;
            default:
            break;
        }
    } while (ch<=3);
    
}
s *push(s*t)
{
    s*p=NULL;
    p=(s*)malloc(sizeof(s));
    if(p!=NULL)
    {
        printf("enter the data");
        scanf("%d",&p->data);
        p->next=t;
        t=p;
    }
    return t;
}
s *pop(s*t)
{
    s*p=NULL;
    if(t==NULL)
    {
        printf("stack underflow");
    }
    else
    {
        p=t;
        // printf("popped elements----");
        // printf("%d ",t->data);
        t=t->next;
    }
    return t;
}

void disprec(s*t)
{
    if(t!=NULL)
    {
        int x;
        x=t->data;
        t=pop(t);
        disprec(t);
        printf("%d",x);
    }
    free(t);
}