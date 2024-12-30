#include<stdio.h>
#include<stdlib.h>
typedef struct double_list
{
    struct double_list *prev;
    int data;
    struct double_list *next;
}dl;
dl* create(dl*);
dl* del(dl*);
void disp(dl*);
void dispb(dl*);
int main()
{
  dl*F=NULL,*R=NULL;
  int ch;
  do
  {
    printf("ENTER MENU\n1-create\n2-display\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        R=create(R);
        if(F==NULL)
        F=R;
        break;
        case 2:
        F=del(F);
        if(F==NULL)
        R=NULL;
        break;
        case 3:
        disp(F);
        break;
        case 4:
        dispb(R);
        break;                    // display in backward direction
    }
  } while (ch<=4);
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

dl* del(dl*F)
{
    dl*p=NULL;
   if(F==NULL)
   {
     printf("underflow");
   }
   else
   {
     p=F;
     printf("%d",p->data);
     F=F->next;
     free(p);
   }
   return F;
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


void dispb(dl *R)            ///bcktracking is possble in double link list
{
    if (R == NULL)
    {
        printf("underflow\n");
    }
    while (R!= NULL)
    {
        printf("%d  ", R->data);
        R = R->prev;
    }
}