#include<stdio.h>
#define max 5
int push1(int [],int,int);
int push2(int [],int,int);
int pop1(int [],int);
int pop2(int [],int);
void disp(int [],int ,int);
int main()
{
   int stack[max], top1 = -1,top2 = max;
   int ch;
   do
   {
      printf("\n1-push1\n2-push2\n3pop1-\n4-pop2\n5-display\n");
      scanf("%d", &ch);
      switch (ch)
      {
        case 1:
        printf("enter the first stack\n");
        top1 = push1(stack,top1,top2);
        break;
        case 2:
        printf("enter the second stack\n");
        top2 = push2(stack,top1,top2);
        break;   
        case 3:
        top1=pop1(stack,top1);
        break;
        case 4:
        top2=pop2(stack,top2);
        break;
        case 5:
        disp(stack,top1,top2);
        break;
        default:
        printf("invalid choice---");
        break;
      }
   } while (ch>=1 && ch <= 5);
   return 0;
}
// here we are pushing simply and keepinf t2 constant---------
int push1(int stack[],int t1,int t2)
{
    int x;
    if(t2-t1>1)
    {
        scanf("%d",&x);
        t1++;
        stack[t1]=x;
    }
    else
    printf("stack 1 is full");
    return t1;
}
//here we are pushing the values to stack 2 from back side w.h.o max and t1 cons rhega-----
int push2(int stack[],int t1,int t2)
{
    int x;
    if(t2-t1>1)
    {
        scanf("%d",&x);
        t2--;
        stack[t2]=x;
    }
    else
    printf("stack 2 is full");
    return t2; 
}

int pop1(int stack[],int t1)
{
    if(t1>=0)
    {
        printf("%d",stack[t1]);
        t1--;  
    }
    else
    printf("stack 1 is empty");
    return t1;
}
int pop2(int stack[],int t2)
{
    if(t2<max)
    {
        printf("%d",stack[t2]);
        t2++;
    }
    else
    printf("stack 2 is empty");
    return t2;
}

void disp(int stack[],int t1,int t2)
{
    if(t1==-1 && t2==max)
    printf("both are empty stack");
    else
    printf("stack 1---\n");
    for(int i=0;i<=t1;i++)
    printf("%d ",stack[i]);
    printf("\n");
    printf("stack 2---\n");
    for(int i=max-1;i>=t2;i--)
    printf("%d ",stack[i]);
}

//CHAT GPT BABA--------


// #include <stdio.h>
// #define max 5

// int push1(int [], int, int);
// int push2(int [], int, int);
// int pop1(int [], int *);
// int pop2(int [], int *);
// void disp(int [], int, int);

// int main() {
//     int stack[max], top1 = -1, top2 = max;
//     int ch;

//     do {
//         printf("\n1 - push1\n2 - push2\n3 - pop1\n4 - pop2\n5 - display\n");
//         scanf("%d", &ch);
//         switch (ch) {
//             case 1:
//                 printf("Enter the element for the first stack: ");
//                 top1 = push1(stack, top1, top2);
//                 break;
//             case 2:
//                 printf("Enter the element for the second stack: ");
//                 top2 = push2(stack, top1, top2);
//                 break;   
//             case 3:
//                 if (top1 >= 0) {
//                     int poppedValue = pop1(stack, &top1);
//                     printf("Popped element from stack1: %d\n", poppedValue);
//                 } else {
//                     printf("Stack1 is empty!\n");
//                 }
//                 break;
//             case 4:
//                 if (top2 < max) {
//                     int poppedValue = pop2(stack, &top2);
//                     printf("Popped element from stack2: %d\n", poppedValue);
//                 } else {
//                     printf("Stack2 is empty!\n");
//                 }
//                 break;
//             case 5:
//                 disp(stack, top1, top2);
//                 break;
//             default:
//                 printf("Invalid choice---\n");
//                 break;
//         }
//     } while (ch >= 1 && ch <= 5);

//     return 0;
// }

// int push1(int stack[], int t1, int t2) {
//     if (t2 - t1 > 1) {
//         int x;
//         scanf("%d", &x);
//         t1++;
//         stack[t1] = x;
//     } else {
//         printf("Stack1 is full!\n");
//     }
//     return t1;
// }

// int push2(int stack[], int t1, int t2) {
//     if (t2 - t1 > 1) {
//         int x;
//         scanf("%d", &x);
//         t2--;
//         stack[t2] = x;
//     } else {
//         printf("Stack2 is full!\n");
//     }
//     return t2; 
// }

// int pop1(int stack[], int *t1) {
//     if (*t1 >= 0) {
//         return stack[(*t1)--]; // Return the popped element and decrement t1
//     }
//     return -1; // Indicate empty stack
// }

// int pop2(int stack[], int *t2) {
//     if (*t2 < max) {
//         return stack[(*t2)++]; // Return the popped element and increment t2
//     }
//     return -1; // Indicate empty stack
// }

// void disp(int stack[], int t1, int t2) {
//     if (t1 == -1 && t2 == max) {
//         printf("Both stacks are empty.\n");
//         return;
//     }
    
//     printf("Stack 1: ");
//     for (int i = 0; i <= t1; i++) {
//         printf("%d ", stack[i]);
//     }
//     printf("\n");

//     printf("Stack 2: ");
//     for (int i = max - 1; i >= t2; i--) {
//         printf("%d ", stack[i]);
//     }
//     printf("\n");
// }
