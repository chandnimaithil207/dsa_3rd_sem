#include<stdio.h>
#include<stdlib.h>
typedef struct cir_list
{
    int data;
    struct cir_list *next;
}cl;
void inslast(cl**,cl**);
cl* beg(cl*,cl*);
void del(cl** ,cl** );
void disp(cl*);
int main()
{
    cl*F=NULL,*R=NULL;
    int ch;
    do
    {
        printf("ENTER MENU\n1-insert\n2-insbeg\n3-display\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            inslast(&F,&R);
            break;
            case 2:
            F=beg(R,F);
            break;
            case 3:
            disp(F);
            break;
        }
    }while (ch<=3);
    return 0;    
}

void inslast(cl**F1,cl**R1)
{
    cl*p=NULL;
    p=(cl*)malloc(sizeof(cl));
    if(p!=NULL)
    {
    printf("Enter the element");
    scanf("%d",&p->data);
    if((*R1)==NULL)
    {
        (*F1)=p;
        *R1=p;
        (*R1)->next=(*R1);
    }
    else
    {
        p->next=(*R1)->next;
        (*R1)->next=p;
        (*R1)=p;
    }
    }
}

cl* beg(cl *R1,cl *F1)
{
    cl*p=NULL;
    p=(cl*)malloc(sizeof(cl));
    if(p!=NULL)
    {
    printf("Enter the element");
    scanf("%d",&p->data);
    if(R1==NULL)
    {
        F1=p;
        R1=p;
        R1->next=R1;
    }
    else
    {
        p->next=R1->next;
        R1->next=p;
    }
    }
    return F1;
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



