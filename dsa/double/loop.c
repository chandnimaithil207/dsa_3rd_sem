#include<stdio.h>
#include<stdlib.h>
typedef struct double_list
{
    struct double_list *prev;
    int data;
    struct double_list *next;
}dl;
dl* create(dl*);
int detect(dl*);
void disp(dl*);
void dispb(dl*);
int main()
{
  dl*F=NULL,*R=NULL;
  int ch,c;
  do
  {
    printf("ENTER MENU\n1-create\n2-detectloop\n3-display\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        R=create(R);
        if(F==NULL)
        F=R;
        break;
        case 2:
        c=detect(F);
        if(c==1)
        printf("Loop detected");
        else
        printf("Loop doesn't exist");
        break;
        case 3:
        disp(F);
        break;                 
    }
  } while (ch<=3);
  return 0;
}

dl* create(dl*R)
{
    dl*p=NULL;
    p=(dl*)malloc(sizeof(dl));
    if(p!=NULL)
    {
        printf("enter the element \n");
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

int detect(dl*F)
{
    dl*slow=NULL,*fast=NULL;
    if(F==NULL)
    {
     printf("underflow");
    }
    else
    {
      slow=F;
      fast=F;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        {
            return 1;
        }
    }
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