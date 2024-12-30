#include<stdio.h>
#include<stdlib.h>
typedef struct cir_list
{
    int data;
    struct cir_list *next;
}cl;
cl* create(cl*,cl*);
cl* cir(cl*);
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
            F=create(F,R);
            break;
            case 2:
            F=cir(F);
            break;
            disp(F);
            break;
        }
    }while (ch<=3);
    return 0;    
}

cl* create(cl*F,cl*R)
{
    cl*p=NULL;
    p=(cl*)malloc(sizeof(cl));
    if(p!=NULL)
    {
    printf("Enter the element");
    scanf("%d",&p->data);
    if(R==NULL && F==NULL)
    {
        R=p;
        F=p;
        p->next=F;
    }
    else
    {
        R->next=p;
        R=p;
        R->next=NULL;
    }
    
    }
    return F;
}

cl* cir(cl *F)
{
    cl*p=NULL;
    if(F==NULL)
    printf("link list is empty");
    else
    {
        p=F;
        while(p->next!=NULL)
        p=p->next;
        p->next=F;
    }
    return F;
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



