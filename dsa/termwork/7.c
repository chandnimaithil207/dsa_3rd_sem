#include<stdio.h>
#include<string.h>
void quick_sort(char[][100],int,int);
int main()
{
    int i,j,n;
    printf("ENter number of names: ");
    scanf("%d",&n);
    char arr[n][100];
    printf("\nENter names: ");
    for(i=0;i<n;i++)
    {
        scanf("%s",arr[i]);
    }
    printf("unsorted array :\n");
    for(i=0;i<n;i++)
    {
        printf("%s\n",arr[i]);
    }
    quick_sort(arr,0,n-1);
    printf("Sorted array:\n");

    for(i=0;i<n;i++)
    {
        printf("%s\n",arr[i]);
    }
    return 0;
}
void quick_sort(char arr[][100],int lb,int ub)
{
    int i=lb,j=ub;
    char key[100],temp[100];
    strcpy(key,arr[lb]);
    if(lb>=ub)
        return;
    while(i<j)
    {
        while(strcmp(arr[i],key)<=0 && i<j)
            i++;
        while(strcmp(arr[j],key)>0)
            j--;
        if(i<j)
        {
            strcpy(temp, arr[i]);
            strcpy(arr[i], arr[j]);
            strcpy(arr[j], temp);
        }
    }
    strcpy(arr[lb],arr[j]);
    strcpy(arr[j],key);

    quick_sort(arr,lb,j-1);
    quick_sort(arr,j+1,ub);
}