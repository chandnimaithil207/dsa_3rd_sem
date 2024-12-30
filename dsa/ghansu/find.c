#include<stdio.h>
#include<stdlib.h>
typedef struct list
{
    int data;
    struct list *next;
}s;
s* create(int *);
void display(s*);
void findno(s*);
int main()
{
    int ch,flag=0,c=0;
    s *ptr=NULL;  
    do
    {
      printf("\nENTER MENU\n1-create\n2-display\n");
      scanf("%d",&ch);
      switch(ch)
      {
        case 1:
        ptr=create(&c);
        break;
        case 2:
        display(ptr);
        break;
        case 3:
        findno(ptr);
        default:
        break;       
        
      }
    } while (ch<=3);
    return 0;
}



s* create(int *q)
{
    s* p=NULL,*l=NULL,*r=NULL;
    int ch,v;
    do{
        p=(s*)malloc(sizeof(s));
        if(p!=NULL)
        {
            printf("enter data");
            scanf("%d",&v);
            p->data=v;
            *q=*q+1;
            if(l==NULL&&r==NULL)
            {
                l=p;
                r=p;
            }
            else
            {
                r->next=p;
                r=p;
            }
            r->next=NULL;
            printf("do you want to continue-");
            scanf("%d",&ch);
            if(ch==0)
            {
                break;
            }
        }
    }while(1);
    return l;
}
void findno(s* ptr)
{
    int n,flag=0;
    s *p=NULL;
    p=ptr;
    printf("enter the no to be searched");
    scanf("%d",&n);
    while(p!=NULL)
    {
        if(p->data==n)
        {
           flag=1;
           break;
        }
        p=p->next;

    }
    if(flag>0)
    printf("elements is found");
    else
    printf("elememt is not found");
}

void display(s* ptr)
{
    s *p=NULL;
    p=ptr;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}