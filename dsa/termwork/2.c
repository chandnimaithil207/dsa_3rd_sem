// // /*Q2.Write a menu driven program to delete duplicate name(if any) in the single Link list. The information
// // field of each node should contain name and noll no of students.*/
// // #include <stdio.h>
// // #include <stdlib.h>
// // typedef struct list
// // {
// //     int name[10];
// //     int roll;
// //     struct list *next;
// // } s;
// // s *create();
// // void deldup(s *);
// // void display(s *);
// // int main()
// // {
// //     s *L = NULL,*R=NULL;
// //     char name1[100];
// //     int ch,roll_no;
// //     do
// //     {
// //         printf("ENTER MENU \n1-create\n2-reverse\n3-display\n");
// //         scanf("%d", &ch);
// //         switch (ch)
// //         {
// //         case 1:
// //             printf("enter name");
// //             getchar();
// //             fgets(name1, sizeof(name1), stdin);
// //             printf("enter roll number");
// //             scanf("%d", &roll_no);
// //             R = create(L, R, name1, roll_no);
// //             if (L == NULL)
// //             L = R;
// //             break;
// //         case 2:
// //             deldup(L);
// //             break;
// //         case 3:
// //             display(L);
// //             break;
// //         default:
// //             break;
// //         }
// //     } while (ch <= 3);
// //     return 0;
// // }

// // s *create(s*L,s*R,char name[],int roll)
// // {
// //     s *p = NULL, *R = NULL, *L = NULL;
// //     int c;
// //     while (1)
// //     {
// //         p = (s *)malloc(sizeof(s));
// //         if (p != NULL)
// //         {
// //             printf("enter the element");
// //             scanf("%s", &p->name);
// //             scanf("%d", &p->roll);
// //             p->next = NULL;
// //             if (L == NULL && R == NULL)
// //             {
// //                 L = p;
// //                 R = p;
// //             }
// //             else
// //             {
// //                 R->next = p;
// //                 R = p;
// //             }
// //             R->next = NULL;
// //         }
// //         printf("do you want to continue ---press 1/0");
// //         scanf("%d", &c);
// //         if (c == 0)
// //             break;
// //     }
// //     return L;
// // }

// // void deldup(s *L)
// // {
// //     if (L == NULL && L->next == NULL)
// //     {
// //     }
// // }

// // void display(s *L)
// // {
// //     s *p = L;
// //     if (p == NULL)
// //     {
// //         printf("The list is empty.\n");
// //         return;
// //     }
// //     while (p != NULL)
// //     {
// //         printf("Name:%s ,Roll no. %d\n", p->name, p->roll);
// //         p = p->next;
// //     }
// //     printf("\n");
// // }
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// typedef struct list
// {
//   char name[100];
//   int roll;
//   struct list *next;
// } s;
// s *create(s *, s *, char[], int);
// void duplicate(s *);
// void disp(s *);
// int main()
// {
//   s *L = NULL, *R = NULL;
//   int ch, roll_no;
//   char name1[100];
//   do
//   {
//     printf("ENTER CHOICE\n1-create \n2-delete duplicate\n3-display\n");
//     scanf("%d", &ch);
//     switch (ch)
//     {
//     case 1:
//       printf("enter name");
//       getchar();
//       fgets(name1, sizeof(name1), stdin);
//       printf("enter roll number");
//       scanf("%d", &roll_no);
//       R = create(L, R, name1, roll_no);
//       if (L == NULL)
//         L = R;
//       break;
//     case 2:
//       duplicate(L);
//       break;
//     case 3:
//       disp(L);
//       break;
//     default:
//       break;
//     }
//   } while (ch <= 3);
//   return 0;
// }

// s *create(s *L, s *R, char name[], int roll_no)
// {
//   s *p = NULL;
//   p = (s *)malloc(sizeof(s));
//   if (p != NULL)
//   {
//     strcpy(p->name, name);
//     p->roll = roll_no;
//     p->next = NULL;
//     if (L == NULL && R == NULL)
//     {
//       L = p;
//       R = p;
//     }
//     else
//     {
//       R->next = p;
//       R = p;
//     }
//   }
//   return R;
// }

// void duplicate(s *L)
// {
//   s *current = L, *prev = NULL, *temp = NULL;

//   while (current != NULL && current->next != NULL)
//   {
//     prev = current;
//     temp = current->next;

//     while (temp != NULL)
//     {
//       if (strcmp(current->name, temp->name) == 0)
//       {

//         prev->next = temp->next;
//         free(temp);
//         temp = prev->next;
//       }
//       else
//       {
//         prev = temp;
//         temp = temp->next;
//       }
//     }
//     current = current->next;
//   }
// }

// void disp(s *L)
// {
//   s *p = NULL;
//   p = L;
//   if (p == NULL)
//   {
//       printf("The list is empty.\n");
//       return;
//   }
//   while (p != NULL)
//   {
//     printf("Roll_no:%d Name:%s ",p->roll,p->name);
//     p = p->next;
//   }
// }

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list
{
    char name[100];
    int roll;
    struct list *next;
} s;

s *create(s *L, char name[], int roll_no);
void duplicate(s *L);
void disp(s *L);

int main()
{
    s *L = NULL;
    int ch, roll_no;
    char name1[100];

    do
    {
        printf("ENTER CHOICE\n1-create \n2-delete duplicate\n3-display\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter name: ");
            getchar(); 
            fgets(name1, sizeof(name1), stdin);
            name1[strcspn(name1, "\n")] = 0; 
            printf("Enter roll number: ");
            scanf("%d", &roll_no);
            L = create(L, name1, roll_no);
            break;
        case 2:
            duplicate(L);
            break;
        case 3:
            disp(L);
            break;
        default:
            break;
        }
    } while (ch <= 3);
    
    return 0;
}
//Function to create a single linked list
s *create(s *L, char name[], int roll_no)
{
    s *p = (s *)malloc(sizeof(s));
    if (p != NULL)
    {
        strcpy(p->name, name);
        p->roll = roll_no;
        p->next = NULL;

        if (L == NULL) 
        {
            L = p;
        }
        else
        {
            s *R = L;
            while (R->next != NULL) 
            {
                R = R->next;
            }
            R->next = p;
        }
    }
    return L;
}
//Function to delete the duplicate name
void duplicate(s *L)
{
    s *current = L, *prev = NULL, *temp = NULL;

    while (current != NULL && current->next != NULL)
    {
        prev = current;
        temp = current->next;

        while (temp != NULL)
        {
            if (strcmp(current->name, temp->name) == 0)
            {
                prev->next = temp->next; 
                free(temp);               
                temp = prev->next;        
            }
            else
            {
                prev = temp;            
                temp = temp->next;      
            }
        }
        current = current->next;
    }
}

void disp(s *L)
{
    s *p = L;
    if (p == NULL)
    {
        printf("The list is empty.\n");
        return;
    }
    
    while (p != NULL)
    {
        printf("Roll_no: %d Name: %s\n", p->roll, p->name); 
        p = p->next;
    }
}
