// /*Write a C program to find the node in the  double linked list , at which the two linked list are intersected.*/
// #include <stdio.h>
// #include <stdlib.h>
// typedef struct dl
// {
//     int data;
//     struct dl *prev;
//     struct dl *next;
// } dl;
// dl* create(dl**,int *);
// dl* findnode(dl*,dl*,int *,int*);
// void disp(dl*);
// int main()
// {
//     dl *p1 = NULL, *p2 = NULL, *p3 = NULL;
//     dl *R=NULL,*L=NULL;
//     int *c1=0,*c2=0;
//     R = create(&R,&c1);
//     if(L==NULL)
//     L=R;
//     printf("\n First double linkedlist ::");
//     disp(p1);
//     R = create(&R,&c2);
//     if(L==NULL)
//     L=R;
//     printf("\n Second double linkedlist::");
//     disp(p2);
//     p3=findnode(p1,p2,&c1,&c2);
//     if(p3!=NULL)
//     {
//         printf("Intersection found at node with data: %d\n", p3->data);
//     }
//     else
//     {
//         printf("No intersection found\n");
//     }
//     return 0;
// }

// dl *create(dl**R,int *c)
// {
//     dl*p=NULL;
//     p=(dl*)malloc(sizeof(dl));
//     if(p!=NULL)
//     {
//         printf("enter the element \n");
//         scanf("%d",&p->data);
//         if(*R==NULL)
//         {
//             (*R)=p;
//             (*R)->prev=NULL;
//         }
//         else
//         {
//             (*R)->next=p;
//             p->prev=*R;
//             *R=p;
//         }
//         c++;
//         (*R)->next=NULL;
//     }
//     return *R;
// }

// dl* findnode(dl*p1,dl*p2,int *c1,int *c2)
// {
//     int diff = (*c1) - (*c2);
//     dl* temp1 = p1;
//     dl* temp2 = p2;

//     if (*c1>*c2) {
//         for (int i = 0; i < diff; i++) {
//             temp1 = temp1->next;
//         }
//     } else {
//         for (int i = 0; i < diff; i++) {
//             temp2 = temp2->next;
//         }
//     }
//     while (temp1 != NULL && temp2 != NULL) {
//         if (temp1 == temp2) {
//             return temp1;
//         }
//         temp1 = temp1->next;
//         temp2 = temp2->next;
//     }

//     return NULL;
// }

// void disp(dl*L)
// {
//     dl*p=NULL;
//     while(p!=NULL)
//     {
//         printf("%d ",p->data);
//         p=p->data;
//     }
// }
#include <stdio.h>
#include <stdlib.h>

typedef struct dl
{
    int data;
    struct dl *prev;
    struct dl *next;
} dl;

dl *create(dl **, int *);
dl *findnode(dl *, dl *, int *, int *);
void disp(dl *);

int main()
{
    dl *p1 = NULL, *p2 = NULL, *intersection = NULL;
    dl *R1 = NULL, *R2 = NULL;
    int c1 = 0, c2 = 0;

    // Create the first doubly linked list
    R1 = create(&R1, &c1);
    if (p1 == NULL)
        p1 = R1;
    printf("\nFirst doubly linked list:\n");
    disp(p1);

    // Create the second doubly linked list
    R2 = create(&R2, &c2);
    if (p2 == NULL)
        p2 = R2;
    printf("\nSecond doubly linked list:\n");
    disp(p2);

    // Find the intersection point
    intersection = findnode(p1, p2, &c1, &c2);

    if (intersection != NULL)
    {
        printf("Intersection found at node with data: %d\n", intersection->data);
    }
    else
    {
        printf("No intersection found\n");
    }

    return 0;
}

dl *create(dl **R, int *count)
{
    dl *p = NULL, *temp = NULL;
    int val, c;
    *count = 0;

    while (1)
    {
        p = (dl *)malloc(sizeof(dl));
        if (p != NULL)
        {
            printf("Enter data for node: ");
            scanf("%d", &val);
            p->data = val;
            p->prev = NULL;
            p->next = NULL;

            if (*R == NULL)
            {
                *R = p;
            }
            else
            {
                temp = *R;
                while (temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = p;
                p->prev = temp;
            }

            (*count)++;
        }

        printf("Do you want to countinue?Press 1/0");
        scanf("%d", &c);
        if (c == 0)
            break;
    }

    return *R;
}

dl *findnode(dl *p1, dl *p2, int *c1, int *c2)
{
    int diff = (*c1) - (*c2);
    dl *temp1 = p1;
    dl *temp2 = p2;

    if (*c1 > *c2)
    {
        for (int i = 0; i < diff; i++)
        {
            temp1 = temp1->next;
        }
    }
    else if (*c2 > *c1)
    {
        for (int i = 0; i < diff; i++)
        {
            temp2 = temp2->next;
        }
    }
    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->data == temp2->data)
        {
            return temp1;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return NULL;
}

void disp(dl *L)
{
    dl *p = L;
    if (p == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
