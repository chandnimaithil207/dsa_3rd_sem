#include <stdio.h>
#include <stdlib.h>
typedef struct poly
{
    int coff;
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
    disp(p1);
    p2 = create();
    printf("\n Second Poly ::");
    disp(p2);
    p3 = addpoly(p1, p2);
    printf("\n Addition of polys ::");
    disp(p3);
}

poly *create()
{
    poly *R = NULL, *L = NULL, *p = NULL;
    int ch, ex, v;
    while (1)
    {
        printf("enter the coffecient and exponent");
        scanf("%d%d", &ex, &v);
        p = (poly *)malloc(sizeof(poly));

        p->exp = ex;
        p->coff = v;
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
        if (p1->exp == p2->exp)
        {
            p->exp = p1->exp;
            p->coff = p1->coff + p2->coff;
            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->exp > p2->exp)
        {
            p->exp = p1->exp;
            p->coff = p1->coff;
            p1 = p1->next;
        }
        else
        {
            p->exp = p2->exp;
            p->coff = p2->coff;
            p2 = p2->next;
        }
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

    return (L);
}

void disp(poly *p3)
{
    while (p3 != NULL)
    {
        printf("%dx^%d", p3->coff, p3->exp);
        p3 = p3->next;
    
    }
}
