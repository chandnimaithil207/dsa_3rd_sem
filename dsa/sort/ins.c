#include <stdio.h>
#include <stdlib.h>
void in_sort(int[], int);
int main()
{
    int a[100], n, key, i;
    printf("enter the array size");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    in_sort(a, n);
    return 0;
}

void in_sort(int a[], int n)
{
    int i, t = 0, j;
    for (i = 1; i < n; i++)
    {
        t = a[i];
        j = i - 1;
        while (j >= 0 && t < a[j])
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = t;
    }
    for(j=0;j<n;j++)
    printf("%d ",a[j]);
}