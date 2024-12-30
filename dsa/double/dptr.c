#include<stdio.h>
#include<stdlib.h>
typedef struct double_list
{
    struct double_list *prev;
    int data;
    struct double_list *next;
}dl;
void create(dl**);
void del(dl**);
void disp(dl*);
void last(dl*);
int main()
{
  dl*F=NULL,*R=NULL;
  int ch;
  do
  {
    printf("ENTER MENU\n1-create\n2-delete\n3-last\n4-display\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        create(&R);
        if(F==NULL)
        F=R;
        break;
        case 2:
        del(&F);
        if(F==NULL)
        R=NULL;
        break;
        case 3:
        last(F);
        break;
        case 4:
        disp(F);
        break;
    }
  } while (ch<=4);
  return 0;
}

void create(dl**R)
{
    dl*p=NULL;
    p=(dl*)malloc(sizeof(dl));
    if(p!=NULL)
    {
        printf("enter the element \n");
        scanf("%d",&p->data);
        if(*R==NULL)
        {
            *R=p;
            (*R)->prev=NULL;
        }
        else
        {
            (*R)->next=p;
            p->prev=(*R);
            (*R)=p;
        }
        (*R)->next=NULL;
    }
}

void del(dl**F)
{
    dl*p=NULL;
   if(*F==NULL)
   {
     printf("underflow");
   }
   else
   {
     p=(*F);
     printf("%d",p->data);
     (*F)=(*F)->next;
     free(p);
   }
}

void disp(dl*F)
{
    if(F==NULL)
    {
        printf("underflow\n");
    }
    while(F!=NULL)
    {
        printf("%d  ",F->data);
        F=F->next;
    }
}

void last(dl*F)
{
    dl*t=NULL,*p=NULL;
    p=F;
    while(p->next!=NULL)
    {
        p=p->next;        
    }
    printf("last element is--%d",p->data);
    free(p);
}
