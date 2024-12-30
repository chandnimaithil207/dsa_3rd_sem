// /*Write a C program to find and delete the node with second minimum data in the single link list.*/
// #include<stdio.h>
// #include<stdlib.h>
// typedef struct list
// {
//     int data;
//     struct list *next;
// }s;
// s* create();
// void sort(s*);
// void display(s*);
// int main()
// {
//     s*L=NULL;
//     int ch;
//     do
//     {
//         printf("ENTER MENU \n1-create\n2-second minimum element\n3-display\n");
//         scanf("%d",&ch);
//         switch (ch)
//         {
//         case 1:
//             L=create();
//             break;
//         case 2:
//             sort(L);
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

// void sort(s*L)
// {
//     s*p=NULL;
//     int t;
//     s* i=NULL,*j=NULL;
//     p=L;
//     if(p==NULL && p->next==NULL)
//     {
//         return ;
//     }
//     for(i=p;i!=NULL;i=i->next)
//     {
//         for(j=i->next;j!=NULL;j=j->next)
//         {
//             if(i->data>j->data)
//             {
//                 t=i->data;
//                 i->data=j->data;
//                 j->data=t;
//             }
//         }
//     }
//     printf("the second mimum element in the given linked list is %d",i->next->data);
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

// Function declarations
s *create();
void display(s *);
void delete_second_minimum(s *);
void sort(s *);
s *delete_node(s *, int);

int main()
{
    s *L = NULL;
    int ch;
    do
    {
        printf("ENTER MENU \n1-create\n2-delete second minimum element\n3-display\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            L = create();
            break;
        case 2:
            delete_second_minimum(L);
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

// Function to create a linked list
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
            if (L == NULL && R == NULL)
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
        printf("Do you want to continue? Press 1/0: ");
        scanf("%d", &c);
        if (c == 0)
            break;
    }
    return L;
}

// Function to display the linked list
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

// Function to find and delete the second minimum element in the list
void delete_second_minimum(s *L)
{
    if (L == NULL || L->next == NULL)
    {
        printf("The list has fewer than two elements.\n");
        return;
    }

    sort(L);

    s *p = L;
    int second_min = p->next->data;

    printf("The second minimum element is %d\n", second_min);

    // Delete the second minimum element
    L = delete_node(L, second_min);
    display(L);
}

// Function to delete a node with a specific value
s *delete_node(s *L, int value)
{
    if (L == NULL)
        return NULL;

    // If the head contains the value to be deleted
    if (L->data == value)
    {
        s *temp = L;
        L = L->next;
        free(temp);
        return L;
    }

    s *current = L;
    while (current->next != NULL)
    {
        if (current->next->data == value)
        {
            s *temp = current->next;
            current->next = current->next->next;
            free(temp);
            return L;
        }
        current = current->next;
    }
    return L; // Value not found, return list unchanged
}

// Function to sort the linked list in ascending order
void sort(s *L)
{
    s *i = NULL, *j = NULL;
    int t;

    if (L == NULL || L->next == NULL)
    {
        return;
    }

    for (i = L; i != NULL; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
        {
            if (i->data > j->data)
            {
                t = i->data;
                i->data = j->data;
                j->data = t;
            }
        }
    }
}
