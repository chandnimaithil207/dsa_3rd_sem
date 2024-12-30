
//dynamic memeory allocation
//create a node using single linked list

#include<stdio.h>
#include<stdlib.h>
typedef struct list
{
    int data;
    struct list *next;

} sl;
int main()
{
    sl *p=NULL;
    int x;
    p=(sl*)malloc(sizeof(sl));
    scanf("%d",&x);
    p->data=x;
    p->next=NULL;
    printf("%d %d",p->data,p->next);
    return 0;
}