#include<stdio.h>
#include<stdlib.h>
typedef struct list
{
    struct list *prev;
    int data;
    struct list *next;    
}dl;
void ins(dl**,dl**);
void disp(dl*);
int main()
{
    dl *F=NULL,*R=NULL;
    int ch;
    do
    {
        printf("ENTER MENU\n1-insert\n2-delete\n3-display");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            ins(&F,&R);
            break;
            case 2:
            disp(F);
            break;
        }
    } while (ch<=2);
    return 0;
}

void ins(dl**F,dl**R)
{
    dl *p=NULL,*q=NULL;
    p=(dl*)malloc(sizeof(dl));
    if(p!=NULL)
    {
        printf("enter the element:");
        scanf("%d",&p->data);
        if((*R)==NULL && (*F)==NULL)
        {
            p->prev=NULL;
            (*R)=p;
            (*F)=p;
        }
        else if(p->data<(*F)->data)
        {
            p->next=(*F);
            (*F)->prev=p;
            (*F)=p;
            p->prev=NULL;
        }
        else if(p->data>(*R)->data)
        {           
            (*R)->next=p;
            p->prev=(*R);
            *R=p;
        }
        else
        {            //insrt in b/w the nodes
            q=*F;
            while(q->data<p->data)
            {
                q=q->next;
            }
            p->next=q;
            p->prev=q->prev;
            q->prev->next=p;
            q->prev=p;;
        }
    }
}


void disp(dl*F)
{
   while(F!=NULL )
   {
    printf("%d ",F->data);
    F=F->next;
   }
}