#include <stdio.h>
#include <stdlib.h>
#define max 100
void quick(int[],int, int);
int main()
{
    int a[max], n,i,lb=0,ub=0;
    printf("enter the array size");
    scanf("%d", &n);
    ub=n-1;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    quick(a,lb,ub);
    printf("Array after quick sort");
    for(i=0;i<n;i++)
    printf("%d ",a[i]);
    return 0;
}

void quick(int a[],int lb,int ub)
{
    int key=a[lb],i=lb,j=ub,t=0;
    if(lb>=ub)
    return;
    while(i<j)
    {
        while(key>=a[i] && i<j)
        {
            i++;
        }
        while(key<a[j])
        {
            j--;
        }
        if(i<j)
        {
            t=a[i];
            a[i]=a[j];
            a[j]=t;
        }
    }
    a[lb]=a[j];
    a[j]=key;
    quick(a,lb,j-1);
    quick(a,j+1,ub);

}


// #include<stdio.h>
// void quick(int[],int,int);
// int main()
// {
//     int arr[20],n,i,j;
//     printf("Enter range: ");
//     scanf("%d",&n);
//     printf("Enter enteries: ");
//     for(i=0;i<n;i++)
//     {
//         scanf("%d",&arr[i]);
//     }
//     for(i=0;i<n;i++)
//     {
//         printf("%d ",arr[i]);
//     }
//     quick(arr,0,n-1);
//     printf("\nSorted array\n");
//     for(i=0;i<n;i++)
//     {
//         printf("%d ",arr[i]);
//     }
//     return 0;
// }

// void quick(int arr[],int lb,int ub)
// {
//     int key=arr[lb],i=lb,j=ub,t=0;
//     if(lb>=ub)
//         return;
//     while(i<j)
//     {
//         while(key>=arr[i] && i<j)
//             i++;
//         while(key<arr[j])
//             j--;
//         if(i<j)
//         {
//             t=arr[i];
//             arr[i]=arr[j];
//             arr[j]=t;
//         }
//     }
//     arr[lb]=arr[j];
//     arr[j]=key;

//     quick(arr,lb,j-1);
//     quick(arr,j+1,ub);
// }