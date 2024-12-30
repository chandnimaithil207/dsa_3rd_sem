#include<stdio.h>
#include<stdlib.h>

typedef struct tree_type
{
    struct tree_type *left;
    int data;
    struct tree_type *right ;
}tree;
void insert (tree **,int);
void inorder(tree *);
void second_heigh(tree*);
void delete (tree**,int);
void common_parent(tree*,int*);
int height(tree*);
void leftcount(tree*,int*);
int main()
{
    tree * root=NULL;
    int ch,num,key,count,heigh,lc;
    do
    {
        printf("\n1.Insert\n2.Inorder\n3.second heighest\n4.Delete\n5.commman parent\n6.Heightof tree\n7.Left count\n");
        printf("\nEnter choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("ENter num");
            scanf("%d",&num);
            insert (&root,num);
            break;
        case 2:
            inorder(root);
            break;
        case 3:
            second_heigh(root);
            break;
        case 4:
            printf("\nEnter key:");
            scanf("%d",&key);
            delete(&root,key);
            break;
        case 5:
            count=0;
            common_parent(root,&count);
            printf("Roots having common parent are: %d ",2*count);
            break;
        case 6:
            heigh=height(root);
            printf("Height of tree is: %d",heigh);
            break;
        case 7:
            lc=0;
            leftcount(root->left,&lc);
            printf("total Left node: %d",lc);
            break;
        }
    }while(ch<8);
    return 0;
}

void insert(tree** rt,int n)
{
    if(*rt==NULL)
    {
        *rt=(tree*) malloc (sizeof(tree));
        (*rt)->data=n;
        (*rt)->left=NULL;
        (*rt)->right=NULL;
    }
    else
    {
        if(n<(*rt)->data)
            insert(&(*rt)->left,n);
        else
            insert(&(*rt)->right,n);
    }
}

void inorder (tree * rt)
{
    if(rt==NULL)
        return;
    else
    {
        inorder(rt->left);
        printf("%d ",rt->data);
        inorder (rt->right);
        return;
    }
}

void preorder(tree*rt)
{
    if(rt==NULL)
        return;
    else
    {
        printf("%d ",rt->data);
        preorder(rt->left);
        preorder(rt->right);
        return;
    }
}

// void second_heigh(tree *rt)
// {
//     if(rt==NULL)
//         return;
//     else
//     {
//         while((rt->right->right)!=NULL)
//         {
//             rt=rt->right;
//         }
//         printf("%d",rt->data);
//     }
//     return;
// }
void delete(tree**rt,int key)
{
    tree* temp;
    if(*rt==NULL)
        return;

    else
    {
        if(key<(*rt)->data)
            delete(&(*rt)->left,key);
        else if (key>(*rt)->data)
             delete(&(*rt)->right,key);
        else
        {
            if((*rt)->right==NULL && (*rt)->left==NULL)
            {
                free(*rt);
                *rt=NULL;
            }
            else if((*rt)->right!=NULL && (*rt)->left==NULL)
            {
                temp=(*rt);
                *rt=(*rt)->right;
                free(temp);
            }
            else if((*rt)->right==NULL && (*rt)->left!=NULL)
            {
                temp=(*rt);
                *rt=(*rt)->left;
                free(temp);
            }
            else if ((*rt)->right!=NULL && (*rt)->left!=NULL)
            {
                temp=(*rt)->right;
                while((temp)->left!=NULL)
                    temp=(temp)->left;

                (*rt)->data=temp->data;
                delete(&(*rt)->right,temp->data);
            }
        }
    }
}

void common_parent(tree *rt,int *c)
{
    if(rt==NULL)
    {
        return;
    }
    if(rt->left!=NULL && rt->right!=NULL)
    {
        (*c)++;
    }
    common_parent(rt->left,c);
    common_parent(rt->right,c);

}
int height(tree*rt)
{
    int left,right;
    if(rt==NULL)
        return-1;
    left=height(rt->left);
    right=height(rt->right);
    return (left > right? left:right)+1;
}
void leftcount(tree*rt,int *c)
{
    if(rt==NULL)
        return;
    else if(rt->left!=NULL)
    {
        (*c)++;

    }
    leftcount(rt->left,c);
    leftcount(rt->right,c);
    
}

//SECOND HIGHEST .
void second_heigh(tree *root) {
    // If the tree is empty or has only one node, there's no second-highest value
    if (root == NULL || (root->left == NULL && root->right == NULL)) {
        printf("No second-highest value.\n");
        return;
    }

    tree *parent = NULL;
    tree *current = root;

    // Traverse to the rightmost node (largest element)
    while (current->right != NULL) {
        parent = current;
        current = current->right;
    }

    // Case 1: If the largest node has a left child, the second-highest value is the rightmost child of the left subtree.
    if (current->left != NULL) {
        current = current->left;
        while (current->right != NULL) {
            current = current->right;
        }
        printf("Second highest value: %d\n", current->data);
    }
    // Case 2: If the largest node has no left child, then the parent is the second-highest value.
    else if (parent != NULL) {
        printf("Second highest value: %d\n", parent->data);
    }
}
