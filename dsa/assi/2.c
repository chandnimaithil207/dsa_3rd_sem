#include <stdio.h>
#include <stdlib.h>
typedef struct list
{
    int process_id;
    int time_required;
    struct list *next;
} ll;
void insertion(ll **l, ll **r, int id, int time_required);
void deletion(ll **l, ll **r);
void time_sharing(ll *l);
void display(ll *l);
int main()
{
    ll *l = NULL, *r = NULL;
    int ch, id, time_required;
    do
    {
        printf("\nPress the certain keys to do the desired operation:-\n");
        printf("1-Insert Process\n2-Delete Process\n3-Display Process Queue\n4-Time Sharing Simulation\n5-Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        printf("\n");
        switch (ch)
        {
        case 1:
            printf("Enter process ID: ");
            scanf("%d", &id);
            printf("Enter time required by process (in ns): ");
            scanf("%d", &time_required);
            insertion(&l, &r, id, time_required);
            break;
        case 2:
            deletion(&l, &r);
            break;
        case 3:
            display(l);
            break;
        case 4:
            time_sharing(l);
            break;
        case 5:
            printf("Thank you for using this program!!\n");
            break;
        default:
            printf("Wrong choice\n");
        }
    } while (ch != 5);
    return 0;
}
void insertion(ll **l, ll **r, int id, int time_required)
{
    ll *p = (ll *)malloc(sizeof(ll));
    if (p == NULL)
    {
        printf("Couldn't Allocate Memory!\n");
        return;
    }
    p->process_id = id;
    p->time_required = time_required;
    p->next = NULL;

    if (*l == NULL)
    {
        *l = *r = p;
        (*r)->next = *l;
    }
    else
    {
        (*r)->next = p;
        *r = p;
        (*r)->next = *l;
    }
}
void deletion(ll **l, ll **r)
{
    if (*l == NULL)
    {
        printf("Process Queue is empty!\n");
        return;
    }

    ll *p = *l;
    printf("Process %d is removed from the queue\n", (*l)->process_id);

    if (*l == *r)
    {
        free(p);
        *l = *r = NULL;
    }
    else
    {
        *l = (*l)->next;
        (*r)->next = *l; 
        free(p);
    }
}
void display(ll *l)
{
    if (l == NULL)
    {
        printf("Process Queue is empty!\n");
        return;
    }

    ll *p = l;
    printf("Process Queue:-\n");
    do
    {
        printf("Process ID: %d, Time Required: %d ns\n", p->process_id, p->time_required);
        p = p->next;
    } while (p != l);
    printf("\n");
}
void time_sharing(ll *l)
{
    if (l == NULL)
    {
        printf("No processes to simulate!\n");
        return;
    }
    
    const int time_slice = 10; 
    ll *current = l;

    printf("Simulating Time Sharing...\n");
    while (1)
    {
        int all_completed = 1;  

        ll *start = current;
        do
        {
            if (current->time_required > 0)
            {
                printf("Process %d is executing...\n", current->process_id);

                if (current->time_required <= time_slice)
                {
                    printf("Process %d completed in %d ns.\n", current->process_id, current->time_required);
                    current->time_required = 0; 
                }
                else
                {
                    printf("Process %d executed for %d ns.\n", current->process_id, time_slice);
                    current->time_required -= time_slice;
                }

                if (current->time_required > 0)
                    all_completed = 0; 
            }
            
            current = current->next;
        } while (current != start); 

        if (all_completed)
        {
            printf("All processes are completed!\n");
            break;
        }
    }
}