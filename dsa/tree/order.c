#include<stdio.h>
#include<stdlib.h>
typedef struct tree_type
{
    struct tree_type*left;
    int data;
    struct tree_type*right;
}tree;
void ins(tree **,int );
void preorder(tree *);
void inorder(tree *);
void postorder(tree *);
int main()
{
    int ch,n;
    tree *root=NULL;
    do
    {
        printf("enter menu\n1-insert\n2-preorder\n3-inorder\n4-postorder\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("enter the element to insert");
            scanf("%d",&n);
            ins(&root,n);
            break;
            case 2:
            printf("the elements in preorder of BST\n");
            preorder(root);
            break;
            case 3:
            printf("the elements in inorder of BST\n");
            inorder(root);
            break;
            case 4:
            printf("the elements in postorder of BST\n");
            postorder(root);
            break;
            case 5:
            printf("exit");
            break;
        }
    } while (ch >=1 && ch<=4);
    return 0;
}

void ins(tree **rt,int n)
{
    if(*rt==NULL)
    {
        (*rt)=(tree*)malloc(sizeof(tree));
        (*rt)->data=n;
        (*rt)->left=NULL;
        (*rt)->right=NULL;
    }
    else
    {
        if(n<(*rt)->data)
        ins(&((*rt)->left),n);
        else
        ins(&((*rt)->right),n);
    }
}

void inorder(tree *rt)
{
    if(rt==NULL)
    return;
    else
    {
        inorder(rt->left);
        printf("%d ",rt->data);
        inorder(rt->right);
        return ;
    }
}

void preorder(tree *rt)
{
    if(rt==NULL)
    return;
    else
    {
        printf("%d ",rt->data);
        preorder(rt->left);
        preorder(rt->right);
        return ;
    }
}

void postorder(tree *rt)
{
    if(rt==NULL)
    return;
    else
    {
        postorder(rt->left);
        postorder(rt->right);
        printf("%d ",rt->data);
        return ;
    }
}