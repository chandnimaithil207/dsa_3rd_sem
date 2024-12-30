#include<stdlib.h>
#include<stdio.h>
#define max 100
int bnsearch(int [],int,int,int);
int main()
{
    int a[max],i,n,lb=0,ub,f=0,key;
    printf("enter the array size");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    ub=n-1;
    printf("enter the key to found\n");
    scanf("%d",&key);
    f=bnsearch(a,lb,ub,key);
    if(f==1)
    printf("key is found");
    else
    printf("key is not found");
    return 0;
}

int bnsearch(int a[],int lb,int ub,int key)
{
    int mid=0,f=0;
    while(lb<=ub)
    {
        mid=(lb+ub)/2;
        if(a[mid]==key)
        {
            return  1;
        }
        else if(a[mid]>key)
        {
            ub=mid-1;
        }
        else
        {
            lb=mid+1;
        }
    }
    return 0;
}