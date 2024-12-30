#include <stdio.h>
#include <stdlib.h>
typedef struct poly
{
	int exp;
	int val;
	struct poly *next;
} poly;
void create(poly **);
poly *add(poly *, poly *);
void display(poly *);
int main()
{
	poly *p1 = NULL, *p2 = NULL, *p3 = NULL;
	int ch;
	printf("\nPolynomial-1:-\n");
	create(&p1);
	printf("\nPolynomial-2:\n");
	create(&p2);
	printf("\nPolynomial-1:-\n");
	display(p1);
	printf("\nPolynomial-2:\n");
	display(p2);
	p3 = add(p1, p2);
	printf("\nPolynomial-3:\n");
	display(p3);
	return 0;
}

void create(poly **po)
{   
    poly *copy= NULL;
	poly *r = *po;
	int ch = 1;
	poly *p = NULL;
	printf("\nEnter the data to create a polynomial:-\n\n");
	while (ch)
	{
		p = (poly *)malloc(sizeof(poly));
		if (p == NULL)
		{
			printf("Memory allocation failed\n");
		}
		else
		{
			printf("Enter value: ");
			scanf("%d", &(p->val));
			printf("Enter exponent: ");
			scanf("%d", &(p->exp));
            copy = *po;
            while(copy!=NULL && copy->exp > p->exp)
            {
                copy=copy->next;
            }
            if(copy!=NULL)
            {
                copy->val+=p->val;
            }
            else
            {
                if (*po == NULL)
				    *po = p;
			    else
				    (r)->next = p;
			    r = p;
            }		
		}
		printf("\nPress 0 to stop and 1 to continue: ");
		scanf("%d",&ch);
	}
	printf("\nPolynomial created!\n");
}

void display(poly *l)
{
	if (l == NULL)
		printf("Polynomial is empty!\n");
	else
	{
		while (l->next != NULL)
		{
			if (l->exp == 0)
				printf("%d + ", l->val);
			else if (l->exp == 1)
				printf("%dx + ", l->val);
			else
				printf("%dx^%d + ", l->val, l->exp);
			l = l->next;
		}
		if (l->exp == 0)
			printf("%d\n", l->val);
		else if (l->exp == 1)
			printf("%dx\n", l->val);
		else
			printf("%dx^%d\n", l->val, l->exp);
		l = l->next;
	}
}

poly *add(poly *p1, poly *p2)
{
	poly *copy1 = p1, *copy2 = p2, *copy3 = NULL, *p3 = NULL, *p = NULL, *l = NULL;

	while (copy1!= NULL)
	{
		copy2 = p2;
		while (copy2 != NULL && copy2->exp != copy1->exp)
			copy2 = copy2->next;
		p = (poly *)malloc(sizeof(poly));
		p->exp = copy1->exp;
		p->val = copy1->val;
		p->next = NULL;
		if (copy2 != NULL && copy2->exp == p->exp)
			p->val += copy2->val;
		if (p3 != NULL)
			p3->next = p;
		else
			l = p;
		p3 = p;
		copy1 = copy1->next;
	}
	copy2 = p2;
	while (copy2 != NULL)
	{
		copy3 = l;
		while (copy3 != NULL && copy3->exp != copy2->exp)
			copy3 = copy3->next;
		if (copy3 == NULL)
		{
			p = (poly *)malloc(sizeof(poly));
			p->exp = copy2->exp;
			p->val = copy2->val;
			p->next = NULL;
			if (p3 != NULL)
				p3->next = p;
			else
				l = p;
			p3 = p;
		}
		copy2 = copy2->next;
	}
	return l;
}




//corrt



#include <stdio.h>
#include <stdlib.h>

typedef struct poly {
    int exp;
    int val;
    struct poly *next;
} poly;

void create(poly **);
poly *add(poly *, poly *);
void display(poly *);

int main() 
{
    poly *p1 = NULL, *p2 = NULL, *p3 = NULL;
    printf("\nPolynomial-1:\n");
    create(&p1);
    printf("\nPolynomial-2:\n");
    create(&p2);

    printf("\nPolynomial-1:\n");
    display(p1);
    printf("\nPolynomial-2:\n");
    display(p2);

    p3 = add(p1, p2);
    printf("\nPolynomial-3:\n");
    display(p3);
    return 0;
}

void create(poly **po) 
{
    poly *r = NULL;
    int ch = 1;
    printf("\nEnter the data to create a polynomial:\n\n");

    while (ch) {
        poly *p = (poly *)malloc(sizeof(poly));
        if (p == NULL) {
            printf("Memory allocation failed\n");
            exit(1);  
        }

        printf("Enter value: ");
        scanf("%d", &(p->val));
        printf("Enter exponent: ");
        scanf("%d", &(p->exp));
        p->next = NULL;

        // Insert node in sorted order
        poly **ptr = po;
        while (*ptr != NULL && (*ptr)->exp > p->exp) {
            ptr = &(*ptr)->next;
        }
        if (*ptr != NULL && (*ptr)->exp == p->exp) {
            (*ptr)->val += p->val;
            free(p);
        } else {
            p->next = *ptr;
            *ptr = p;
        }

        printf("\nPress 0 to stop and 1 to continue: ");
        scanf("%d", &ch);
    }
    printf("\nPolynomial created!\n");
}

void display(poly *l) 
{
    if (l == NULL) {
        printf("Polynomial is empty!\n");
        return;
    }

    while (l != NULL) {
        if (l->val == 0) {
            l = l->next;
            continue;
        }
        if (l->exp == 0) {
            printf("%d", l->val);
        } else if (l->exp == 1) {
            printf("%dx", l->val);
        } else {
            printf("%dx^%d", l->val, l->exp);
        }
        l = l->next;
        if (l != NULL && l->val > 0) {
            printf(" + ");
        }
    }
    printf("\n");
}

poly *add(poly *p1, poly *p2)
{
    poly *p3 = NULL, **ptr = &p3;
    while (p1 != NULL && p2 != NULL)
    {
        if (p1->exp > p2->exp)
        {
            *ptr = (poly *)malloc(sizeof(poly));
            if (*ptr == NULL) 
            {
                printf("Memory allocation failed\n");
                exit(1);
            }
            (*ptr)->exp = p1->exp;
            (*ptr)->val = p1->val;
            (*ptr)->next = NULL;
            p1 = p1->next;
        } 
        else if (p1->exp < p2->exp)
        {
            *ptr = (poly *)malloc(sizeof(poly));
            if (*ptr == NULL) 
            {
                printf("Memory allocation failed\n");
                exit(1);
            }
            (*ptr)->exp = p2->exp;
            (*ptr)->val = p2->val;
            (*ptr)->next = NULL;
            p2 = p2->next;
        }
        else
        {
            *ptr = (poly *)malloc(sizeof(poly));
            if (*ptr == NULL)
            {
                printf("Memory allocation failed\n");
                exit(1);
            }
            (*ptr)->exp = p1->exp;
            (*ptr)->val = p1->val + p2->val;
            (*ptr)->next = NULL;
            p1 = p1->next;
            p2 = p2->next;
        }
        ptr = &(*ptr)->next;
    }

    while (p1 != NULL)
    {
        *ptr = (poly *)malloc(sizeof(poly));
        if (*ptr == NULL) 
        {
            printf("Memory allocation failed\n");
            exit(1);
        }
        (*ptr)->exp = p1->exp;
        (*ptr)->val = p1->val;
        (*ptr)->next = NULL;
        p1 = p1->next;
        ptr = &(*ptr)->next;
    }

    while (p2 != NULL) 
    {
        *ptr = (poly *)malloc(sizeof(poly));
        if (*ptr == NULL) 
        {
            printf("Memory allocation failed\n");
            exit(1);
        }
        (*ptr)->exp = p2->exp;
        (*ptr)->val = p2->val;
        (*ptr)->next = NULL;
        p2 = p2->next;
        ptr = &(*ptr)->next;
    }

    return p3;
}