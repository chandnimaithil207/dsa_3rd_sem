// #include <stdio.h>
// #include <stdlib.h>
// typedef struct list
// {
//   int data;
//   struct list *next;
// } sl;
// sl *create();
// void sort(sl *);
// void disp(sl *);
// int main()
// {
//   int ch;
//   sl *L = NULL;
//   do
//   {
//     printf("\nENTER MENU\n1-create\n2-sort\n3-display\n");
//     scanf("%d", &ch);
//     switch (ch)
//     {
//     case 1:
//       L = create();
//       break;
//     case 2:
//       sort(L);
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
// sl *create()
// {
//   sl *p = NULL, *R = NULL, *L = NULL;
//   int c;
//   while(1)
//   {
//   p = (sl *)malloc(sizeof(sl));
//   if (p != NULL)
//   {
//     scanf("%d", &p->data);
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
//   printf("to cont--press 1/0");
//   scanf("%d",&c);
//   if(c==0)
//   break;
//   }
//   return L;
// }

// void sort(sl *L)
// {
//   sl *p = NULL, *q = NULL;
//   int t;
//   p = L;
//   q = p->next;
//   while (p != NULL)
//   {
//     while (q != NULL)
//     {
//       if (p->data > q->data)
//       {
//         t = p->data;
//         p->data = q->data;
//         q->data = t;
//       }
//       q = q->next;
//     }
//     p = p->next;
//   }
//   // while(p!=NULL)
//   // {
//   //   printf("%d ",p->data);
//   //   p=p->next;
//   // }
// }

// void disp(sl *L)
// {
//   sl *p = L;
//   if(p==NULL)
//   printf("list is empty");
//   while (p != NULL)
//   {
//     printf("%d ", p->data);
//     p = p->next;
//   }
// }
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to split the linked list into two halves
void split(struct Node* head, struct Node** front, struct Node** back) {
    struct Node* fast;
    struct Node* slow;
    
    slow = head;
    fast = head->next;
    
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    
    *front = head;
    *back = slow->next;
    slow->next = NULL;
}

// Function to merge two sorted linked lists
struct Node* merge(struct Node* front, struct Node* back) {
    // Base cases
    if (front == NULL) return back;
    if (back == NULL) return front;
    
    // Start with the node that has the smaller value
    if (front->data <= back->data) {
        front->next = merge(front->next, back);
        return front;
    } else {
        back->next = merge(front, back->next);
        return back;
    }
}

// Function to perform merge sort on the linked list
struct Node* mergeSort(struct Node* head) {
    // Base case: if the list is empty or has only one element
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    struct Node* front;
    struct Node* back;
    
    // Split the list into two halves
    split(head, &front, &back);
    
    // Recursively sort the two halves
    front = mergeSort(front);
    back = mergeSort(back);
    
    // Merge the sorted halves
    return merge(front, back);
}

// Function to insert a new node at the beginning of the list
void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Main function to test the sorting algorithm
int main() {
    struct Node* head = NULL;
    
    // Insert data into the linked list
    push(&head, 15);
    push(&head, 10);
    push(&head, 5);
    push(&head, 20);
    push(&head, 3);
    push(&head, 2);
    
    printf("Unsorted Linked List: \n");
    printList(head);
    
    // Sort the linked list using Merge Sort
    head = mergeSort(head);
    
    printf("Sorted Linked List: \n");
    printList(head);
    
    return 0;
}
