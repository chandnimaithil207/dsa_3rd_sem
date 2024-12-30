// #include<stdio.h>
// #include<stdlib.h>
// typedef struct list
// {
//     int data;
//     struct list *next;
// }s;
// s* create(s*,s*);
// int disp(s*,int);
// int main()
// {
//     s *p=NULL,*R=NULL,*L=NULL;
//     int count=0,ch,c=0;
//     do
//     {
//       printf("ENTER MENU\n1-create\n2-display\n");
//       scanf("%d",&ch);
//       switch(ch)
//       {
//         case 1:
//         p=create(L,R);
//         break;
//         case 2:
//         c=disp(L,count);
//         printf("%d",c);
//         break;
//         default:
//         break;       
        
//       }
//     } while (ch<=2);
//     return 0;
// }

// s* create(s*L,s*R)
// {
    
//     s* p=(s*)malloc(sizeof(s));
//     if(p!=NULL)
//     {
//         printf("entr the element");
//         scanf("%d",&p->data);
//         p->next=NULL;
//         if(R==NULL && L==NULL)
//         {
//         R=p;
//         L=p;
//         }
//         else
//         {
//         R->next=p;
//         R=p;
//         }
       
//     }
//     return p;
    
// }
// int  disp(s *L,int count)
// {
//     count =0;
//     printf("hii");
//     s* p=NULL;
//     p=L;
//     if(p!=NULL)
// {
//     do
//     {
//         printf("%d ",p->data);
//         p=p->next;
//         count++;
//     }while(p!=NULL);
// }
// return count;
    
// }



#include<stdio.h>
#include<stdlib.h>
typedef struct list
{
    int data;
    struct list *next;
}s;
s* create(int *);
void display(s*);
int main()
{
    int ch,c=0;
    s *ptr=NULL;  
    do
    {
      printf("\nENTER MENU\n1-create\n2-display\n");
      scanf("%d",&ch);
      switch(ch)
      {
        case 1:
        ptr=create(&c);
        printf("no of node ----%d",c);
        break;
        case 2:
        display(ptr);
        break;
        default:
        break;       
        
      }
    } while (ch<=2);
    return 0;
}



s* create(int *q)
{
    s* p=NULL,*l=NULL,*r=NULL;
    int ch,v;
    do{
        p=(s*)malloc(sizeof(s));
        if(p!=NULL)
        {
            printf("enter data");
            scanf("%d",&v);
            p->data=v;
            *q=*q+1;
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
            printf("do you want to continue-");
            scanf("%d",&ch);
            if(ch==0)
            {
                break;
            }
        }
    }while(1);
    return l;
}

void display(s* ptr)
{
    s *p=NULL;
    p=ptr;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}