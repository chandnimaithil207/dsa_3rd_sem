//queue using doble pointer--------
#include<stdio.h>
#include<stdlib.h>
typedef struct queue
{
  int data;
  struct queue *next;
}q;

void enq(q**,q**);
void deq(q**,q**);
void disp(q*);
int main()
{
   q *f=NULL,*r=NULL;
   int ch,x;
   do
   {
     printf("\nENTER THE MENU:\n1-ENQUE\n2-DEQUEUE\n3-DISPLAY\n");
     scanf("%d",&ch);
     switch(ch)
     {
        case 1:
        enq(&f,&r);
        break;
        case 2:
        deq(&f,&r);
        break;
        case 3:
        disp(f);
        break;
        default:
        printf("invalid option");
        break;
     }
   }while(ch<=3 && ch>=0);
return 0;
}

void enq(q** f1,q** r1)
{
   q *p=NULL;
   int x;
   p=(q*)malloc(sizeof(q));
   if(p!=NULL)
   {
     printf("enter the value");
     scanf("%d",&x);
     p->data=x;
     if(*f1==NULL && *r1==NULL)
        *f1=*r1=p;
     else
     {
        (*r1)->next=p;
        (*r1)=p;
     }
     (*r1)->next=NULL;
      
  }
  else
  printf("memeory is not allocated");
}

void deq(q** f1,q** r1)
{
  q *p=NULL;
  if(*f1==NULL)
  {
    printf("queue is empty");
  }
  else
  {
    p=(*f1);
    printf("%d",(*f1)->data);
    if(*f1==*r1)
      (*f1)=(*r1)=NULL;
    else
      (*f1)=(*f1)->next;
    free(p);
   }
    
}

void disp(q* f) 
{
  if(f==NULL)
    printf("queue is empty");
  else
  {
    while(f!=NULL)
    {
       printf("%d ",f->data);
       f=f->next;
    }
  }
}