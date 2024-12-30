#include <stdio.h>
#define max 5
int cenq(int[], int, int);
int cdeq(int[], int, int);
void disp(int[], int, int);
void peek(int[], int);
void main()
{
    // circular queue-----
    int ch, cq[max], r = -1, f = -1;
    do
    {
        printf("1-enque\n2-dequeue\n3-display\n4-peek\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            r = cenq(cq, f, r);
            if (f == -1)
                f = 0;
            break;
        case 2:
            f = cdeq(cq, f, r);
            if (f == -1)
                r = -1;
            break;
        case 3:
            disp(cq, f, r);
            break;
        case 4:
            peek(cq, f);
            break;
        default:
            break;
        }
    } while (ch <= 4);
}

int cenq(int cq[], int f, int r)
{
    int x;
    if ((r + 1) % max == f)
        printf("queue overflow");
    else
    {
        printf("enter the element:\n");
        scanf("%d", &x);
        r = (r + 1) % max;
        cq[r] = x;
    }
    return r;
}

int cdeq(int cq[], int f, int r)
{
    int x;
    if (f == -1 && r == -1)
        printf("queue empty");
    else
    {
        x = cq[f];
        printf("%d", x);
        if (f == r)
        {
            f = -1;
        }
        else
            f = (f + 1) % max;
    }
    return f;
}

void disp(int cq[], int f, int r)
{
    if (f == -1 && r == -1)
    {
        printf("queue empty");
    }
    else
    {
        while (f != r)
        {
            printf("%d ", cq[f]);
            f = (f + 1) % max;
        }
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