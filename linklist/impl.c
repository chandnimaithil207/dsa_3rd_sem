#include<stdio.h>
#include<stdlib.h>
typedef struct list
{
    int data;
    struct list *next;
}s;
s* create();
s* beforefirstnode(s*);
void afterfirstnode(s*);
void beforelastnode(s*);
void afterlastnode(s*);
s* del(s*);        // deltion of 1st node
s* secdel(s*);    //delete 2nd node
void dellast(s*);   //delete last node
void seclast(s*);   //delete second last
void disp(s*);
int main()
{
    s *p=NULL,*L=NULL,*R=NULL;
    int ch;
    do
    {
        printf("ENTER MENU\n1-create\n2-beforefirst\n3-afterfirstnode\n4-beforelstnode\n5-afterlastnode\n6-deletion\n7-deletionofsecnode\n8-lastnode\n9-deletesecondlast\n10-disp\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            L=create();
            break;
            case 2:
            L=beforefirstnode(L);
            break;
            case 3:
            afterfirstnode(L);
            break;
            case 4:
            beforelastnode(L);
            break;
            case 5:
            afterlastnode(L);
            break;
            case 6:
            L=del(L);
            break;
            case 7:
            L=secdel(L);
            break;
            case 8:
            dellast(L);
            break;
            case 9:
            seclast(L);
            break;
            case 10:
            disp(L);
            break;
        }
    } while (ch<=13);
    return 0;
}

s* create()
{
    s* p=NULL,*R=NULL,*L=NULL;
    int c;
    while(1)
    {
    p=(s*)malloc(sizeof(s));
    if(p==NULL)
    {
        printf("empty");
    }
    else
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
    }
    printf("press 1 to cont---else 0");
    scanf("%d",&c);
    if(c==0)
    break;
    }
    return L;   
}
s* beforefirstnode(s* L)
{
    s* p=NULL;
    p=(s*)malloc(sizeof(s));
    if(p!=NULL)
    {
       printf("enter the element");
       scanf("%d",&p->data);
       p->next=L;
       L=p;
    }
    return L;
}

void afterfirstnode(s*L)
{
    s* p=NULL;
    p=(s*)malloc(sizeof(s));
    if(p!=NULL)
    {
        scanf("%d",&p->data);
        p->next=L->next;
        L->next=p;
    }
}

void beforelastnode(s*L)
{
    s* p=NULL;
    p=(s*)malloc(sizeof(s));
    if(p!=NULL)
    {
        scanf("%d",&p->data);
        while(L->next->next!=NULL)
        L=L->next;
        p->next=L->next;
        L->next=p;       
    }
}

void afterlastnode(s* L)
{
    s*p=NULL;
    p=(s*)malloc(sizeof(s));
    scanf("%d",&p->data);
    while(L->next!=NULL)
    {
    L=L->next;
    }

    L->next=p;
    p->next=NULL;

}

s* del(s*L)
{
    s* p=NULL;
    p=L;
    L=L->next;
    free(p);
    return L;
}

s* secdel(s* L)
{
    s*p=NULL;
    p=L->next;
    L->next=L->next->next;
    free(p);
    return L;
}

void dellast(s* L)
{
    s* p=NULL;
    while(L->next->next!=NULL)
    L=L->next;
    p=L;
    p->next=NULL;
}

void seclast(s*L)
{
    s*p=NULL,*prev=NULL;
    p=L;
    while(p->next->next!=NULL)
    {
       prev=p;
       p=p->next;
    }
    prev->next=p->next;
    free(p);
  

}
void disp(s*L)
{
    while(L!=NULL)
    {
        printf("%d ",L->data);
        L=L->next;
    }

}

 
