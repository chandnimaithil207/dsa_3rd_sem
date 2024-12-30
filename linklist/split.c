#include<stdio.h>
#include<stdlib.h>
typedef struct list
{
    int data;
    struct list *next;
}sl;
sl* create(int*);
void split(sl*,int);
int main()
{
    sl* leftmost=NULL,*rightmost=NULL;
    int ch,count=0;
    do
    {
        printf("enter choice");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: 
                  leftmost= create(&count);
                   break;
                   
            case 2:
                 split(leftmost,count);
                 break;
                   
        }                  
    }while(ch<=3);                
                   
    return 0;
}
sl* create(int *count)
{
    int c;
    sl* p=NULL,*l=NULL,*r=NULL;
    do{
        p=(sl*)malloc(sizeof(sl));
        if(p!=NULL)
        {
            printf("enter data-");
            scanf("%d",&p->data);
            if(l==NULL&&r==NULL)
            {
                l=p;
                r=p;
            }
            else
            {
               r->next=p;
               r=p;
            }
            r->next=NULL;
        }
        *count=*count+1;
        printf("do you want  to continue");
        scanf("%d",&c);
        if(c==0)
        {
            break;
        }
    }while(1);
    return l;
}  

void split(sl*l,int count)
{
    int sp=0,i=1,c=0,info;
   printf("enter node info from which you want to split");
   scanf("%d",&info);
  
   sl* secondlnklist=NULL,*p=NULL;
   p=l;
   while(p!=NULL)
   {
       if(p->data==info)
       {
          break;
       }
       sp++;
       p=p->next;
   }
   p=l;
   while(p!=NULL){
       if(i==sp)
       {
        secondlnklist=p->next;   
        p->next=NULL;
        break;
       }
       i++;
       p=p->next;
   }
   p=l;
   printf("\nlinklist1-");
   while(p!=NULL)
   {
       printf("%d  ",p->data);
       p=p->next;
   }
   p=secondlnklist;
    printf("\nlinklist2-");
   while(p!=NULL)
   {
       printf("%d  ",p->data);
       p=p->next;
   }
}