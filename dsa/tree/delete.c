#include<stdio.h>
#include<stdlib.h>
typedef struct tree_type
{
    struct tree_type*left;
    int data;
    struct tree_type*right;
}tree;
void ins(tree **,int);
tree* del(tree *,int);
void disp(tree *);
int main()
{
    int n,ch,c,v;
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
            printf("Enter number to delete");
            scanf("%d",&v);
            root=del(root,v);
            break;
        case 3:
            disp(root);
            break;
        }
    }while (ch<=3);
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

// tree* del(tree *rt,int v)
// {
//     tree*p=NULL,*t=NULL,*x=NULL,*c=NULL;
//     if(rt->data==v)
//     {
//         if(rt->left==NULL && rt->right== NULL)
//         {
//             free(rt);
//             return NULL;
//         }
//         else if(rt->left!=NULL && rt->right==NULL)
//         {
//             t=rt;
//             rt=rt->left;
//             free(t);
//             return rt;
//         }
//         else if(rt->right!=NULL)
//         {
//             t=rt;
//             rt=rt->right;
//             x=rt;
//             while(x->left!=NULL)
//             {
//                 x=x->left;
//             }
//             x->left=t->left;
//             free(t);
//             return rt;
//         }
//     }
//     else 
//     {
//         x=rt,p=x;
//         while(x!=NULL)
//         {
//             if(x->data!=v)
//             {
//                 x=((x->data)>v?x->left:x->right);
//                 if(x->data==v)
//                 {
//                     break;
//                 }
//                 if(x==NULL)
//                 {
//                     printf("Data not found");
//                     return rt;
//                 }
//                 else
//                 {
//                     if(x->right==NULL && x->left!=NULL)
//                     {
//                         t=x;
//                         x=x->left;
//                     }
//                     if(x->right!=NULL)
//                     {
//                         x=x->right;
//                         c=x;
//                         while(c->left!=NULL)
//                         c=c->left;
//                         c->left=t->left;                        
//                     }
//                     if(p->data>v)
//                     p->left=x;
//                     else
//                     p->right=x;
//                     free(p);
//                     return rt;            
//                 }
//                 if(x->right==NULL && x->left==NULL)
//                 {
//                     x=t;
//                     if(p->data>v)
//                     p->left=NULL;
//                     else
//                     p->right=NULL;
//                     free(t);
//                     return rt;
//                 }
//             }
//         }
//     }
// }

tree* del(tree* rt, int v) {
    if (rt == NULL) {
        return NULL;  // Node not found
    }

    // If the value to be deleted is smaller, move to the left subtree
    if (v < rt->data) {
        rt->left = del(rt->left, v);
    }
    // If the value to be deleted is larger, move to the right subtree
    else if (v > rt->data) {
        rt->right = del(rt->right, v);
    }
    // Node to be deleted is found
    else {
        // Case 1: Node has no children (leaf node)
        if (rt->left == NULL && rt->right == NULL) {
            free(rt);
            return NULL;
        }
        // Case 2: Node has only one child
        else if (rt->left == NULL) {
            tree* temp = rt->right;
            free(rt);
            return temp;
        }
        else if (rt->right == NULL) {
            tree* temp = rt->left;
            free(rt);
            return temp;
        }
        // Case 3: Node has two children
        else {
            // Find the inorder successor (smallest in the right subtree)
            tree* temp = rt->right;
            while (temp->left != NULL) {
                temp = temp->left;
            }

            // Replace the data of the current node with the inorder successor's data
            rt->data = temp->data;

            // Delete the inorder successor
            rt->right = del(rt->right, temp->data);
        }
    }

    return rt;
}


void disp(tree *rt)
{
    if(rt==NULL)
    {
        return ;
    }
    else
    {
        printf("%d",rt->data);
        disp(rt->left);
        disp(rt->right);
        return ;
    }
}

