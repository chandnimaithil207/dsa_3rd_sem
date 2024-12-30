#include<stdio.h>
#include<stdlib.h>
typedef struct tree_type
{
    struct tree_type*left;
    int data;
    struct tree_type*right;
}tree;
void ins(tree **,int);
void disp(tree *);
int main()
{
    int n,ch,c;
    tree *root=NULL;
    do
    {
       printf("enter menu\n1-insert\n2-disp\n");
       scanf("%d",&ch);
       switch(ch)
       {
        case 1:
            printf("enter the element to insert \n");
            scanf("%d",&n);
            ins(&root,n);
            break;
        case 2:
            disp(root);
            break;
        }
    }while (ch<=2);
    return 0;    
}

void  ins(tree **rt,int n)
{
    if(*rt==NULL)
    {
        *rt=(tree*)malloc(sizeof(tree));
        (*rt)->data=n;
        (*rt)->left=NULL;
        (*rt)->right=NULL;
    }
    else
    {
        if(n<(*rt)->data)
        {
            ins(&(*rt)->left,n);
        }
        else
        {
            ins(&(*rt)->right,n);
        }
    }
}


void disp(tree *rt)
{
    if(rt==NULL)
    {
        return ;
    }
    else
    {
        disp(rt->left);
        printf("%d",rt->data);
        disp(rt->right);
        return ;
    }
}

