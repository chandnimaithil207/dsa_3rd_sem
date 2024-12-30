#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data){
    struct node *n; // creating a node pointer
    n = (struct node *) malloc(sizeof(struct node)); // Allocating memory in the heap
    n->data = data; // Setting the data
    n->left = NULL; // Setting the left and right children to NULL
    n->right = NULL; // Setting the left and right children to NULL
    return n; // Finally returning the created node
}

struct node* insert(struct node* root,int data)
{
 struct node* p=root;
 if(root==NULL)
 {
     return createNode(data);
     
 }
 
 
    if(data<root->data) 
    root->left=insert(root->left,data);
    else if(data>root->data)
    root->right=insert(root->right,data);
    return root;
 
    
}
void display_preorder(struct node* root)
{
    
    if(root!=NULL)
   { 
       printf("   %d  ",root->data);
       display_preorder(root->left);
       display_preorder(root->right);
    
   }
}
struct node* minnodeofrightside(struct node* current)
{
    while(current!=NULL && current->left!=NULL)
    {
        current=current->left;
    }
    return current;
}
struct node* delete(struct node* root,int key)
{
    
    if(root==NULL)
    {
       printf("element not found");
       return root;
        
    }
    if(key>root->data)
    root->right=delete(root->right,key);
    else if(key<root->data)
    root->left=delete(root->left,key);
    else
    {
        //case one
           if(root->left==NULL && root->right==NULL) 
          { free(root);
            return NULL;
     // case 2
          }
          if(root->right==NULL) 
          {
         struct node* temp=root;
         root=root->left;
         free(temp);
         }
        else if(root->left==NULL)
        {
         struct node* temp=root;
         root=root->right;
         free(temp);
         
        }else
        {
        //case 3
    
         struct node* temp=minnodeofrightside(root->right);  
         root->data=temp->data;
         root->right=delete(root->right,temp->data);
         
        }
    }
  return root;  
}
int count_leaf_node(struct node *root)
{
   if(root==NULL) 
   {
       return 0;
   }
   if(root->left==NULL&&root->right==NULL)
   {
        return 1;
   }
    return count_leaf_node(root->left)+count_leaf_node(root->right);
    
}
int add(struct node *root)
{
    if(root==NULL)
    return 0;
    int sum=root->data+add(root->left)+add(root->right);
    return sum;
}
int max(struct node *root)
{
    if(root==NULL)
    return 0;
    if(root->right!=NULL)
    return max(root->right);
     else
    return root->data;
}
void secondlargest(struct node *root)
{
    if(root==NULL)
    return;
    static int count=0;
    secondlargest(root->right);
    count++;
    if(count==2)
    {
        printf("second largest =%d ",root->data);
        return;
    }
    secondlargest(root->left);
}
void reverseorder(struct node *root)
{
    if(root==NULL)
    return;

    reverseorder(root->right);
    printf("   %d  ",root->data);
    reverseorder(root->left);
}
int height(struct node *root)
{
    int leftheight;
    int rightheight;
    if(root==NULL)
    return 0;
    rightheight=height(root->right);
    leftheight=height(root->left);
    return(leftheight>rightheight?leftheight:rightheight)+1;
}
int countleftside(struct node *root)
{
    if(root==NULL)
    return 0;
    int count=0;
    struct node *current=root->left;
    while(current!=NULL)
    {
        count++;
        current=current->left;
    }
    return count;
}
int main(){
    struct node* root=NULL;
    
    int data,key;
    int n=0;
    int ch;
    while(1)
    { 
        printf("enter choice");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                   printf("enter data\n");
                   scanf("%d",&data);
                    root = insert(root,data);
                    break;
            case 2:
            display_preorder(root);
            break;
            case 3:
            exit(0);
            break;
            case 4:
            printf("enter value u want to deleted");
            scanf("%d",&key);
            root=delete(root,key);
            break;
            case 5:
    
            printf("total leaf node=%d \n  sum equal =%d",count_leaf_node(root),add(root));
            printf("\n  max  =  %d",max(root));
            break;
            case 6:
            reverseorder(root);
            secondlargest(root);
            break;
            case 7:
           printf("  \n  height%d",height(root));
            break;
            case 8:
            printf(" \nleft node total = %d  ",countleftside(root));
            break;
            
        }
    }

  return 0;
}