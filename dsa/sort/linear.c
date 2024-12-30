#include<stdio.h>
#include<stdlib.h>
void search(int[],int,int);
int main()
{
    int a[100],n,key,i;
    printf("enter the array size");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("enetr the key to find");
    scanf("%d",&key);
    search(a,n,key);
    return 0; 
}

void search(int a[],int n,int key)
{
    int f=0,i,t=0;
    for(i=0;i<n;i++)
    {
        if(a[i]==key)
        {
            f=f+1;
            t=i;
        }
    }
    if(f>0)
    {
        printf("key is found at the index- %d",t);
    }
    else
    {
        printf("key is not found");
    }
    
}