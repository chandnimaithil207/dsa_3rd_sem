#include<stdio.h>
#include<stdlib.h>
typedef struct tree
{
    struct tree*left;
    int data;
    struct tree*right;
}t;
void ins(t **,int);
void nodes(t *,int *);
void leaf(t *,int *);
void onlychild(t *,int *);
void disp(t*);
int main()
{
    t *rt=NULL;
    int ch,n,c;
    do
    {
        printf("\nEnter Menu\n1-Insert\n2-Count nodes\n3-Leaf nodes\n4-Onlychild\n5-display\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("Enter the number");
            scanf("%d",&n);
            ins(&rt,n);
            break;
            case 2:
            c=0;
            nodes(rt,&c);
            printf("Total no. of nodes %d",c);
            break;
            case 3:
            c=0;
            leaf(rt,&c);
            printf("Total no of leaf node %d",c);
            break;
            case 4:
            c=0;
            onlychild(rt,&c);
            printf("Total no of nodes having 1 child %d",c);
            break;
            case 5:
            disp(rt);
            break;

        }

    } while (ch<=5);
    
}

void ins(t **rt,int n)
{
    if(*rt==NULL)
    {
        (*rt)=(t*)malloc(sizeof(t));
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

void nodes(t*rt,int *c)
{
    if(rt==NULL)
    return ;
    else
    {
        (*c)++;
        nodes(rt->left,c);
        nodes(rt->right,c);
    }
}


void leaf(t*rt,int *c)
{
    if(rt==NULL)
    {
    return ;
    }
    else if(rt->right==NULL && rt->left==NULL)
    {
    (*c)++;
    }
    leaf(rt->left,c);
    leaf(rt->right,c);
    
}

void onlychild(t*rt,int *c)
{
    if(rt==NULL)
    {
    return ;
    }
    else if(rt->left==NULL && rt->right!=NULL ||rt->left!=NULL && rt->right==NULL )
    {
    (*c)++;
    }
    onlychild(rt->left,c);
    onlychild(rt->right,c);
    
}


void disp(t*rt)
{
    if(rt==NULL)
    return ;
    else
    {
        disp(rt->left);
        printf("%d ",rt->data);
        disp(rt->right);
        return ;
    }
}
 