#include<stdio.h>
#include<stdlib.h>
typedef struct list
{
    int pr;
    int data;
    struct list *next;
}s;
s* insert(s*,s*,int *);
void del(s*);
void disp(s* ,int *);
int main()
{
    s*p=NULL,*L=NULL,*R=NULL;
    int ch,c=0;
    do
    {
        printf("enetr menu\n1-insert\n2-deletion\n3-display\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            L=insert(L,R,&c);
            break;
            case 2:
            del(L);
            break;
            case 3:
            disp(L,&c);
            break;
        }
    } while (ch<=3);
    return 0;   
}
