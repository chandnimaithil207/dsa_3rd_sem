#include<stdio.h>
#include<stdlib.h>
typedef struct cir_list
{
    int data;
    struct cir_list *next;
}cl;
void create(cl**,cl**);
void del(cl** ,cl** );
void disp(cl*);
int main()
{
    cl*F=NULL,*R=NULL;
    int ch;
    do
    {
        printf("ENTER MENU\n1-insert\n2-delete\n3-display\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            create(&F,&R);
            break;
            case 2:
            del(&F,&R);
            break;
            case 3:
            disp(F);
            break;
        }
    }while (ch<=3);
    return 0;    
}

void create(cl**F1,cl**R1)
{
    cl*p=NULL;
    p=(cl*)malloc(sizeof(cl));
    if(p!=NULL)
    {
    printf("Enter the element");
    scanf("%d",&p->data);
    if((*R1)==NULL && (*F1)==NULL)
    {
        *R1=p;
        *F1=p;
    }
    else
    {
        (*R1)->next=p;
        *R1=p;
        (*R1)->next=(*F1);
    }
    }
}

void del(cl **F1,cl **R1)
{
    cl*p=NULL;
    if(*F1==NULL && *R1==NULL)
    printf("link list is empty");
    else
    {
        p=(*F1);
        printf("%d",(*F1)->data);
        if(*F1==*R1)
        {
            *F1=NULL;
            *R1=NULL;
        }
        (*F1)=(*F1)->next;
        (*R1)->next=(*F1);
        free(p);
    }
}

void disp(cl *F1)
{
    cl *p=NULL;
    p=F1;
    if(F1==NULL)
    {
        printf("circular linkedlist is empty");
    }
    do
    {
        printf("%d ",p->data);
        p=p->next;
    } while (p!=F1);
}



