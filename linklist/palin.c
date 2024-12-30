#include<stdio.h>
#include<stdlib.h>
typedef struct list
{
    int data;
    struct list *next;
}s;
s* create(int *);
void palin(s*);
void disp(s*);
int main()
{
    int ch,c=0;
    s *L=NULL;
    do
    {
        printf("ENTER MENU\n1-create\n2-findpalindrome\n3-disp\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            L=create(&c);
            break;
            case 2:
            palin(L);
            break;
            case 3:
            disp(L);
            break;
            case 4:
            printf("exit");
            break;
        }
    
    } while (ch<=3);
    free(L);
    return 0;
}

s* create(int *c)
{
    int v;
    s*p=NULL,*L=NULL,*R=NULL;
    while(1)
    {
        p=(s*)malloc(sizeof(s));
        if(p!=NULL)
        {
            printf("enter the element---");
            scanf("%d",&p->data);
            if(L==NULL && R==NULL)
            {
                L=p;
                R=p;
            }
            else
            {
                R->next=p;
                R=p;
            }
            *c=*c+1;
            R->next=NULL;
            printf("do u want to contii-----press1/0");
            scanf("%d",&v);
            if(v==0)
            break;
        }
    }
    printf("total no of nodes are---%d\n",*c);
    return L;
}

void palin(s*L)
{
    if(L==NULL && L->next==NULL)
    printf("list is palindrome");
    int i=0,f=0;
    s*slow=NULL,*fast=NULL;
    s*sl=NULL,*fl=NULL;
    s*prev=NULL,*Next=NULL;
    slow=L;
    fast=L;
    while(fast!=NULL && fast->next!=NULL)     ///finding middle node with slow pointer
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    sl=slow->next;
    slow->next=NULL;        //divide into two linklist
    while(sl!=NULL)
    {
        Next=sl->next;
        sl->next=prev;
        prev=sl;
        sl=Next;
    }
    sl=prev;
    fl=L;
    while(sl!=NULL)
    {
    if(sl->data!=fl->data)
    {
        f++;
        break;
    }
    sl=sl->next;
    fl=fl->next;
    }
    if(f>0)
    {
      printf("not palindrome");
    }
    else
    {
      printf("yesss ");
    } 
}

void disp(s*L)
{
    s*p=NULL;
    p=L;
    while(p!=NULL)
    {
        printf("%d  ",p->data);
        p=p->next;
    }
}
