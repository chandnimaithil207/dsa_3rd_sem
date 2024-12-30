#include <stdio.h>
#define max 5
void cenq(int[], int *, int *);
void cdeq(int[], int *, int *);
void disp(int[], int , int );
void peek(int[], int );
int main()
{
    // circular queue using call by reference -----
    int ch, cq[max], r = -1, f = -1;
    do
    {
        printf("ENTER MENU---\n1-enque\n2-dequeue\n3-display\n4-peek\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            cenq(cq, &f, &r);
            break;
        case 2:
            cdeq(cq, &f, &r);
            break;
        case 3:
            disp(cq, f, r);
            break;
        case 4:
            peek(cq, f);
            break;
        default:
            printf("ginti nhi aati kya!!!!!");
            break;
        }
    } while (ch>=1 && ch <= 4);
    return 0;
}
void cenq(int cq[], int *f, int *r)
{
    int x;
    if (((*r + 1) % max) == *f)
        printf("queue overflow");
    else
    {
        printf("enter the element:\n");
        scanf("%d", &x);
        if(*f==-1)
           *f=0;
        *r = ((*r) + 1) % max;
        cq[*r] = x;
    }
}

void cdeq(int cq[], int *f, int *r)
{
    int x;
    if ((*f == -1) && (*r == -1))
        printf("queue empty");
    else
    {
        x = cq[*f];
        printf("%d", x);
        if ((*f) == (*r))
        {
            *f = -1;
        }
        else
            *f = ((*f) + 1) % max;
    }
}

void disp(int cq[], int f, int r)
{
    if (f == -1 && r== -1)
    {
        printf("queue empty");
    }
    else
    {
        do
        {
            printf("%d ", cq[f]);
            f = (f + 1) % max;
        }while (f <= r);
        printf("%d", cq[f]);
    }
}

void peek(int cq[], int f)
{
    if (f == -1)
    {
        printf("queue is empty");
    }
    else
    {
        printf("\n%d", cq[f]);
    }
}