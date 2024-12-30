#include<stdio.h>
#include<stdlib.h>
typedef struct list
{
    int data ;
    struct list *next ;
}s;
s* create();
s* rev(s*);
void revr(s*);
void disp(s*);
int main()
{
    int ch;
    s* L=NULL,*R=NULL,*p=NULL;
    do
    {
        printf("ENTER MENU\n1-create\n2-reverse\n3-recur\n4-display\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            L=create();
            break;
            case 2:
            L=rev(L);
            break;
            case 3:
            revr(L);
            break;
            case 4:
            disp(L);
            break;
            default:
            break;
        }
    } while (ch<=4);
    return 0;
}

s* create()
{
    s*p=NULL,*R=NULL,*L=NULL;
    int c;
    while(1)
    { 
        p=(s*)malloc(sizeof(s));
        if(p!=NULL)
        {
            scanf("%d",&p->data);
            p->next=NULL;
            if(R==NULL && L==NULL)
            {
                R=p;
                L=p;
            }
            else
            {
                R->next=p;
                R=p;
            }
            R->next=NULL;
            printf("to continue-----press1/0");
            scanf("%d",&c);
            if(c==0)
            break;
        }
    }
    return L;
}

s* rev(s*L)
{
    s *Next=NULL,*prev=NULL,*p=NULL;
    p=L;
    printf("hii");
    while(p!=NULL)
    {
        Next=p->next;
        p->next=prev;
        prev=p;
        p=Next;
    }
    L=prev;
    while(L!=NULL)
    {
        printf("%d",L->data);
        L=L->next;
    }
    printf("\n");
    return L;

}

void disp(s*L)
{
    s*p=NULL;
    p=L;
    if(p==NULL)
      printf("linked list is empty");
    else
    {
        while(p!=NULL)
        {
            printf("%d ",p->data);
            p=p->next;
        }
    }
}


void revr(s*L)
{
    s*p1=NULL;
    p1=L;
    if(p1==NULL)
        return ;
        revr(p1->next);
        printf("%d",p1->data);
}
