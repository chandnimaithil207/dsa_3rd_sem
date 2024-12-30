#include<stdio.h>
#include<stdlib.h>
#define max 100
void sel(int [],int);
int main()
{
    int a[max],n;
    printf("Enter size of array");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
    sel(a,n);
    printf("Array after selection sort");
    for(int i=0;i<n;i++)
    printf("%d ",a[i]);
    return 0;
}

void sel(int a[],int n)
{
    int i,j,min=0,pos=0;
    for(i=0;i<n-1;i++)
    {
        min=a[i];
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(min>a[j])
            {
                min=a[j];
                pos=j;
            }
        }
        if(pos!=i)
        {
            a[pos]=a[i];
            a[i]=min;
        }
    }
}
