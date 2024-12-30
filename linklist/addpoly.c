#include <stdio.h>
#include <stdlib.h>
typedef struct poly
{
    int data;
    int exp;
    struct poly *next;
} poly;
poly* create();
poly* addpoly(poly *, poly *);
void disp(poly *);
int main()
{
    poly *p1 = NULL, *p2 = NULL, *p3 = NULL;
    p1 = create();
    printf("\n First Poly ::");
    //disp(p1);
    p2 = create();
    printf("\n Second Poly ::");
    //disp(p2);
    p3 = addpoly(p1, p2);
    printf("\t\n Addition of polys ::");
   // disp(p3);
}

poly *create()
{
    poly *R = NULL, *L = NULL, *p = NULL;
    int ch,v;
    while (1)
    {
        printf("enter the coffecient and exponent");
        scanf("%d", &v);
        p = (poly *)malloc(sizeof(poly));

        p->data = v;
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

        R->next = NULL;
    }
    return (L);
}

poly *addpoly(poly *p1, poly *p2)
{
    poly *p = NULL, *L = NULL, *R = NULL;
    while (p1 != NULL && p2 != NULL)
    {
        p = (poly *)malloc(sizeof(poly));
        p->data=p1->data+p2->data;
       if (L == NULL && R == NULL)
            L = R = p;
        else
        {
            R->next = p;
            R = p;
        }
        R->next = NULL;
    }
    if (p1 != NULL)
    {
        R->next = p1;
    }
    if (p2 != NULL)
        R->next = p2;

    while(p!=NULL)
    {
        printf("%d",p->data);
        p=p->next;
    }
    return L;
    
    
}

// void disp(poly *p3)
// {
//     while (p3 != NULL)
//     {
//         printf("%dx^%d", p3->data, p3->exp);
//         p3 = p3->next;
    
//     }
// }
