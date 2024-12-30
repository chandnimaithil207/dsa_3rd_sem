#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int data;
    struct Stack* next;
} Stack;

// Function to create a new stack node
Stack* createNode(int data) {
    Stack* newNode = (Stack*)malloc(sizeof(Stack));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Push function to add an element to the stack
void push(Stack** top, int data) {
    Stack* newNode = createNode(data);
    newNode->next = *top;
    *top = newNode;
}

// Pop function to remove an element from the stack
int pop(Stack** top) {
    if (*top == NULL) {
        return -1; // Indicating stack is empty
    }
    Stack* temp = *top;
    int poppedValue = temp->data;
    *top = (*top)->next;
    free(temp);
    return poppedValue;
}

// Recursive function to print stack elements in queue-like order
void printStackAsQueue(Stack** top) {
    if (*top == NULL) {
        return; // Base case: if stack is empty
    }

    // Pop the top element
    int data = pop(top);
    
    // Recursive call to print remaining elements
    printStackAsQueue(top);
    
    // Print the popped element
    printf("%d ", data);
}

int main() {
    Stack* top = NULL;

    // Push elements onto the stack
    push(&top, 10);
    push(&top, 20);
    push(&top, 30);
    
    printf("Elements in queue-like order: ");
    printStackAsQueue(&top);
    printf("\n");

    return 0;
}



#include<stdio.h>
#include<stdlib.h>
typedef struct list
{
    int data;
    struct list *next;
}s;
s* create(int*);
void dis(s*);
void display(s*);
s* insert(s*);
s* insertt(s*);
s* insertlast(s*);
s* insertseclast(s*);
s* insertpar(s*);
int main()
{
    int c=0;

    s *ptr=NULL;
    ptr=create(&c);
    printf("\ntotal no. of nodes %d\n",c);
    display(ptr);
 //   printf("\n");
 dis(ptr);
     printf("\n");
    ptr=insert(ptr);
     display(ptr);
     printf("\n");
         ptr=insertt(ptr);
     display(ptr);
     printf("\n");
     insertlast(ptr);
     display(ptr);
          printf("\n");
     insertseclast(ptr);
     display(ptr);
               printf("\n");
     insertpar(ptr);
     display(ptr);
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
/void dis(s ptr)
{
    s *p=NULL;
    p=ptr;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next->next;
    }
}*/
void dis(s* ptr) {
    s *p = ptr;
    while (p != NULL) {
        printf("%d ", p->data);
        if (p->next == NULL) {
            break; // Prevent moving forward if next is NULL
        }
        p = p->next->next; // Move two steps forward, print every second node
    }
}

s* insert(s*ptr)
{
    int val;
    s* p=NULL;
    p=(s*)malloc(sizeof(s));
    printf("enter value to be inserted");
    scanf("%d",&val);
    p->data=val;
    p->next=ptr;
    return p;
}
s* insertt(s*ptr)
{
    int val;
    s* p=NULL;
    p=(s*)malloc(sizeof(s));
    printf("enter value to be inserted");
    scanf("%d",&val);
    p->data=val;
    p->next=ptr->next;
    ptr->next=p;
    return ptr;
}
s* insertlast(s*ptr)
{
    int val;
    s* p=NULL,*last=NULL;
    last=ptr;
    p=(s*)malloc(sizeof(s));
    printf("enter value to be inserted");
    scanf("%d",&val);
    p->data=val;
    while((last->next)!=NULL)
    {
       last=last->next;
    }
    last->next=p;
    p->next=NULL;
    return ptr;
}
s* insertseclast(s*ptr)
{
    int val;
    s* p=NULL,*last=NULL;
    last=ptr;
    p=(s*)malloc(sizeof(s));
    printf("enter value to be inserted");
    scanf("%d",&val);
    p->data=val;
    while((last->next->next)!=NULL)
    {
       last=last->next;
    }
    p->next=last->next;
    last->next=p;
    return ptr;
}
s* insertpar(s*ptr)
{
    int val,c;
    printf("enter at which node-");
    scanf("%d",&c);
    s* p=NULL,*particular=NULL;
    particular=ptr;
    p=(s*)malloc(sizeof(s));
    printf("enter value to be inserted");
    scanf("%d",&val);
    p->data=val;
    while(c>=0)
    {
       particular=particular->next;
       c++;
    }
    p->next=particular->next;
    particular->next=p;
    return ptr;
}