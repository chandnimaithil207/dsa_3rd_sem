#include<stdio.h>
#include<stdlib.h>
typedef struct poly
{
    int expo;
    int coff;
    struct poly *next;
}poly;
poly* create();
poly* addpoly(poly* ,poly* );
void disp(poly*);
int main()
{
    poly *p1=NULL,*p2=NULL,*p3=NULL;
    printf("the first polynomial::");
    p1=create();
    disp(p1);
    printf("the second polynomial::");
    p2=create();
    disp(p2);
    p3=addpoly(p1,p2);
    printf("Addition of the two polynomials::");
    disp(p3);
    return 0;
    
}
poly* create()
{
    poly *p=NULL,*R=NULL,*L=NULL;
    int n,v,ch;
    while(1)
    {
      printf("enter the exponent---\n");
      scanf("%d",&n);
      printf("enter the coffecient---\n");
      scanf("%d",&v);
      p=(poly*)malloc(sizeof(poly));
      if(p!=NULL)
      {
        if(n>=0)
        {
            p->expo=n;
            p->coff=v;
        }
        if(L==NULL && R==NULL)
        {
            L=p;
            R=p;
        }
        else
        {
            R->next=p;
            R=p;
        }
        R->next=NULL;
        
        printf("Do you want to to continue.....press 1/0");
        scanf("%d",&ch);
        if(ch==0)
        break;
        
        free(p);
      }
    
    }
    return L;
}

poly* addpoly(poly *p1,poly *p2)
{
    poly *R=NULL,*L=NULL,*p=NULL;
    while(p1!=NULL && p2!=NULL)
    {
        p=(poly*)malloc(sizeof(poly));
        if(p1->expo==p2->expo)
        {
            p->expo=p1->expo;
            p->coff=p1->coff+p2->coff;
            p1=p1->next;
            p2=p2->next;
        }
        else if(p1->expo > p2->expo)
        {
            p->expo=p1->expo;
            p->coff=p1->coff;
            p1=p1->next;
        } 
        else
        {
            p->expo=p2->expo;
            p->coff=p2->coff;
            p2=p2->next;
        }
        if(R==NULL && L==NULL)
        {
            L=p;
            R=p;
        }
        else
        {
            R->next=p;
            R=p;
        }
        R->next=NULL;
         free(p);
    }
    if(p1!=NULL) 
      R->next=p1;
    else
      R->next=p2;
    
    return L;
   
    
}
void disp(poly *p)
{
    while(p!=NULL)
    {
        printf("%dx^%d",p->coff,p->expo);
        p=p->next;
    }
}


        



    