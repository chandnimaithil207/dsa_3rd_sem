#include<stdio.h>
#include<stdlib.h>
typedef struct list
{
    int data;
    struct list *next;
}sl;
sl* create(int*);
int find(sl*,int*);
int main()
{
    sl* leftmost=NULL,*rightmost=NULL;
    int ch,count;
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
               find(leftmost,&count);
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

int find(sl*leftmost,int *count)
{
    sl*p=NULL;
    p=leftmost;
    int n,i=1;
    printf("total nodes in a linked list =%d\n",*count);
    printf("enter the position to be searched");
    scanf("%d",&n);
    int tosearch=*count-n-1;
    if(p->next==NULL)
    return 1;
    while(p!=NULL)
    {
        while(i<tosearch)
        {
            p=p->next;
            i++;
        }
        tosearch=p->data;
        printf("%d",tosearch);
    }
    return tosearch;
}