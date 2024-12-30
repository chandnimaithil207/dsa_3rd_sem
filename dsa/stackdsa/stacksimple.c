#include <stdio.h>
#define max 5
int push(int[], int);
int pop(int[], int);
void display(int[], int);
void peek(int[], int);
int main()
{
   int stack[max], top = -1;
   int a, b, ch;
   do
   {
      printf("\n1-push\n2-pop\n3-display\n4-peek");
      scanf("%d", &ch);
      switch (ch)
      {
      case 1:
         top = push(stack, top);
         break;
      case 2:
         top = pop(stack, top);
         break;
      case 3:
         display(stack, top);
         break;
      case 4:
         peek(stack, top);
         break;
      default:
         printf("invalid choice---");
         break;
      }
   } while (ch <= 4);
   return 0;
}

int push(int stack[], int top)
{
   int x;
   if (top == max - 1)
   {
      printf("stack overflow");
   }
   else
   {
      scanf("%d", &x);
      top++;
      stack[top] = x;
      // printf("%d",stack[top]);
   }
   return top;
}

int pop(int stack[], int top)
{
   int x;
   if (top == -1)
   {
      printf("stack underflow");
   }
   else
   {
      x = stack[top];
      printf("%d", x);
      top--;
   }
   return top;
}

void display(int stack[], int top)
{
   if (top == -1)
   {
      printf("stack underflow");
   }
   else
   {
      while (top != -1)
      {
         printf("%d", stack[top]);
         top--;
      }
   }
}

void peek(int stack[], int top)
{
   if (top == -1)
   {
      printf("stack is underflow");
   }
   else
   {
      if (top != -1)
      {
         printf("%d", stack[top]);
      }
   }
}