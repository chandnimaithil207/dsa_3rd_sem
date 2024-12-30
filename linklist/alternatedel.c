#include <stdio.h>
#include <stdlib.h>
typedef struct list
{
    int data ;
    struct list *next ;
}s;
s* create(); 
void alter(s*);
void disp(s*);
int main()
{
    int ch;
    s* L=NULL,*R=NULL,*p=NULL;
    do
    {
        printf("ENTER MENU\n1-create\n2-alternate\n3-display\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            L=create();
            break;
            case 2:
            alter(L);
            break;
            case 3:
            disp(L);
            break;
        }
    } while (ch<=3);
    return 0; 
}

s* create()
{
    s *R = NULL, *L = NULL, *p = NULL;
    int ch;
    while (1)
    {
        p = (s *)malloc(sizeof(s));
        if(p!=NULL)
        {
        printf("enter the elemenet");
        scanf("%d",&p->data);
        if (L == NULL && R == NULL)
            L = R = p;
        else
        {
            R->next = p;
            R = p;
        }
        printf("Do you want to con.... press 1/0");
        scanf("%d", &ch);
        if (ch == 0)
            break;
        }
        R->next=NULL;
    }
    return (L);
}

void alter(s*L)
{
    s*p=NULL;
    p=L;
    while(L!=NULL && L->next!=NULL)
    {
        p=L->next;
        L->next=L->next->next;
        free(p);
        L=L->next;
    }
}

void disp(s*L)
{
    s*p=NULL;
    p=L;
    while(p!=NULL)
    {
        printf("%d",p->data);
        p=p->next;
    }
}