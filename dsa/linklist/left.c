#include <stdio.h>
#include <stdlib.h>
typedef struct list
{
    int data;
    struct list *next;
} sl;
int main()
{
    sl *p = NULL, *L = NULL;
    int c;
    while(1)
    {
        p = (sl *)malloc(sizeof(sl));
        if (p != NULL)
        {
            printf("enter the elements");
            scanf("%d", &p->data);
            p->next = L;
            L = p;
        }
        printf("to cont----press1/0");
        scanf("%d", &c);
        if (c == 0)
            break;
    }
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    return 0;
}
