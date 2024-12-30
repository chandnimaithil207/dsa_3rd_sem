// /*Q1. Write a menu driven program to reverse a single linked list in O(N) time with a non-recursive function.*/

// #include<stdio.h>
// #include<stdlib.h>
// typedef struct list
// {
//     int data;
//     struct list *next;
// }s;
// s* create();
// void reverse(s*);
// void display(s*);
// int main()
// {
//     s*L=NULL;
//     int ch;
//     do
//     {
//         printf("ENTER MENU \n1-create\n2-reverse\n3-display\n");
//         scanf("%d",&ch);
//         switch (ch)
//         {
//         case 1:
//             L=create();
//             break;
//         case 2:
//             reverse(L);
//             break;
//         case 3:
//             display(L);
//             break;
//         default:
//             break;
//         }
//     } while (ch<=3);
//     return 0;
// }

// s* create()
// {
//     s*p=NULL,*R=NULL,*L=NULL;
//     int c;
//     while(1)
//     {
//         p=(s*)malloc(sizeof(s));
//         if(p!=NULL)
//         {
//             printf("enter the element");
//             scanf("%d",&p->data);
//             p->next=NULL;
//             if(L==NULL && R==NULL)
//             {
//                 L=p;
//                 R=p;
//             }
//             else
//             {
//                 R->next=p;
//                 R=p;
//             }
//             R->next=NULL;
//         }
//         printf("do you want to continue ---press 1/0");
//         scanf("%d",&c);
//         if(c==0)
//         break;
//     }
//     return L;
// }

// void reverse(s*L)
// {
//     s*Next=NULL,*prev=NULL,*p=NULL;
//     p=L;
//     while(p!=NULL)
//     {
//         Next=p->next;
//         p->next=prev;
//         prev=p;
//         p=Next;
//     }
//     L=prev;
//     printf("\t****OUTPUT*****\n");
//     while(L!=NULL)
//     {
//         printf("%d ",L->data);
//         L=L->next;
//     }
// }

// void display(s*L)
// {
//     s*p=NULL;
//     p=L;
//     while(p!=NULL)
//     {
//         printf("%d ",p->data);
//         p=p->next;
//     }
// }
#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
    int data;
    struct list *next;
} s;

s *create();
void reverse(s **);
void display(s *);
int main()
{
    s *L = NULL;
    int ch;
    do
    {
        printf("ENTER MENU \n1-create\n2-reverse\n3-display\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            L = create();
            break;
        case 2:
            reverse(&L); // Pass address of L to update the head after reversal
            break;
        case 3:
            display(L);
            break;
        default:
            break;
        }
    } while (ch <= 3);
    return 0;
}
// Function to create a single linked list
s *create()
{
    s *p = NULL, *R = NULL, *L = NULL;
    int c;
    while (1)
    {
        p = (s *)malloc(sizeof(s));
        if (p != NULL)
        {
            printf("Enter the element: ");
            scanf("%d", &p->data);
            p->next = NULL;
            if (L == NULL)
            {
                L = p;
                R = p;
            }
            else
            {
                R->next = p;
                R = p;
            }
        }
        printf("Do you want to continue? Press 1 to continue, 0 to stop: ");
        scanf("%d", &c);
        if (c == 0)
            break;
    }
    return L;
}
// Function to reverse a linked list
void reverse(s **L)
{
    s *next = NULL;
    s *prev = NULL;
    s *p = *L;
    while (p != NULL)
    {
        next = p->next;
        p->next = prev;
        prev = p;
        p = next;
    }
    *L = prev; // Update the head of the list to the new reversed list

    printf("\t****OUTPUT*****\n");
    display(*L); // Display the reversed list
}

void display(s *L)
{
    s *p = L;
    if (p == NULL)
    {
        printf("The list is empty.\n");
        return;
    }
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
