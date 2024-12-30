
//static memeory allocation
//create a node using single linked list

#include<stdio.h>
#include<stdlib.h>
typedef struct list
{
    int data;
    float m;
    struct list *next;

} sl;
int main()
{
    sl a,b,c;
    a.data=10;
    b.data=20;
    c.data=30;
    a.next=&b;
    b.next=&c;
    c.next=NULL;
    printf("%d %d\n%d %d",a.data,a.next,b.data,b.next);

    
  
    return 0;
}




 
