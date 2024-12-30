#include<stdio.h>
#include<stdlib.h>
#define max 100
void sort(int [],int);
int main()
{
    int a[max],n,i;
    printf("Enter the size of array");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    sort(a,n);
    for(i=0;i<n;i++)
    printf("%d",a[i]);
}

void sort(int a[],int n)
{
    int i=0,j=0,t=0,f=0;
    for(i=0;i<n;i++)
    {
        f=0;
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                f=1;
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
        if(f==0)
        break;
    }
}