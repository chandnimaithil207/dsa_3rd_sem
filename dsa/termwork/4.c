/*
Q4. Write a C program to   create a single linked list, then find whether there exist any two nodes in the    
       linked list whose multiplication is less than the target value.
       Example:
       Input:  Linked-List =  12->15->3->4->6, Target = 20
       Output: Yes 
*/
#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
typedef struct list
{
    int data;
    struct list *next;
}s;
s* create();
int check(s*,int);
void display(s*);
int main()
{
    s*L=NULL;
    int ch,t;
    do
    {
        printf("ENTER MENU \n1-create\n2-checkMultiplicationLessThanTarget\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            L=create();
            break;
        case 2:
            printf("Enter target value");
            scanf("%d",&t);
            if(check(L,t)==1)
            {
                printf("yesss");
            }
            else
            {
                printf("no");
            }
            break;
        }
    } while (ch<=2);
    return 0;    
}
//Function to create a single linked list
s* create()
{
    s*p=NULL,*R=NULL,*L=NULL;
    int c;
    while(1)
    {
        p=(s*)malloc(sizeof(s));
        if(p!=NULL)
        {
            printf("enter the element");
            scanf("%d",&p->data);
            p->next=NULL;
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
        }
        printf("do you want to continue ---press 1/0");
        scanf("%d",&c);
        if(c==0)
        break;
    }
    return L;
}
//Function To Check Multiplication Less Than Target
int check(s*L,int t)
{
    s*p=NULL,*temp;
    p=L;
    while(p!=NULL)
    {
        temp=p->next;
        while(temp!=NULL)
        {
            if(p->data*temp->data<t)
            {
                return 1;
            }
            temp=temp->next;
        }
        p=p->next;
    }
    return 0;
}

