#include<stdio.h>
#include<stdlib.h>
typedef struct double_list
{
    struct double_list *prev;
    int data;
    struct double_list *next;
}dl;
dl*create(dl*);
void alternate(dl*);
void disp(dl*);
int main()
{
  dl*F=NULL,*R=NULL;
  int ch;
  do
  {
    printf("ENTER MENU\n1-create\n2-alternatedisplay\n3-display\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        R=create(R);
        if(F==NULL)
        F=R;
        break;
        case 2:
        alternate(F);
        break;
        case 3:
        disp(F);
        break;
    }
  }while(ch<=3);
  return 0;
}

dl* create(dl*R)
{
    dl*p=NULL;
    p=(dl*)malloc(sizeof(dl));
    if(p!=NULL)
    {
        printf("enter the element");
        scanf("%d",&p->data);
        if(R==NULL)
        {
            R=p;
            R->prev=NULL;
        }
        else
        {
            R->next=p;
            p->prev=R;
            R=p;
        }
        R->next=NULL;
    }
    return R;
}

void alternate(dl*F)
{
    dl*p=NULL;
    int c=0;
    if(F==NULL)
    printf("double linked list is emptty");

    p=F;
    while(p!=NULL)
    {
        c++;
        p=p->next;
    }

    if(c==1)
    {
        printf("the only element in the list is %d\n",p->data);
    }
    
    dl*start=F;
    dl*end=F;

    while(end->next!=NULL)
    end=end->next;

    while(start!=NULL && end!=NULL && start!=end)
    {
        printf("%d ",start->data);
        start=start->next;

        if(start!=end)
        {
            printf("%d ",end->data);
            end=end->prev;
        }
        if(end==start)
        {
            printf("%d ",start->data);
        }
    }

}

void disp(dl*F)
{
    dl*p=NULL;
    p=F;
    while(p!=NULL)
    {
        printf("%d  ",p->data);
        p=p->next;
    }
}
