#include <stdio.h>
#include <stdlib.h>

void merge_sort(int a[], int t[], int lb, int ub);
void merge(int a[], int t[], int lb, int mid, int ub);

int main() {
    int a[100], t[100], n, lb = 0, ub, i;
    printf("Enter the array size: ");
    scanf("%d", &n);

    printf("Enter the array elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    ub = n - 1;
    merge_sort(a, t, lb, ub);

    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}

void merge_sort(int a[], int t[], int lb, int ub) {
    if (lb < ub) {
        int mid = (ub + lb) / 2;
        merge_sort(a, t, lb, mid);    // Sorting the first half
        merge_sort(a, t, mid + 1, ub); // Sorting the second half
        merge(a, t, lb, mid, ub);      // Merging the sorted halves
    }
}

void merge(int a[], int t[], int lb, int mid, int ub) {
    int i = lb, j = mid + 1, k = lb;

    // Merge the two halves into the temporary array t[]
    while (i <= mid && j <= ub) {
        if (a[i] < a[j]) {
            t[k] = a[i];
            i++;
        } else {
            t[k] = a[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements from the left half, if any
    while (i <= mid) {
        t[k] = a[i];
        i++;
        k++;
    }

    // Copy the remaining elements from the right half, if any
    while (j <= ub) {
        t[k] = a[j];
        j++;
        k++;
    }

    // Copy the sorted data back into the original array
    for (i = lb; i <= ub; i++) {
        a[i] = t[i];
    }
}


// #include <stdio.h>
// #include <stdlib.h>
// void merge_sort(int[],int[],int,int);
// void merge(int[],int [],int, int,int);
// int main()
// {
//     int a[100],t[100],n,lb=0,ub,i;
//     printf("enter the array size");
//     scanf("%d", &n);
 
//     for (i = 0; i < n; i++)
//     {
//         scanf("%d", &a[i]);
//     }
//        ub=n-1;
//     merge_sort(a,t,lb,ub);
//     return 0;
// }


// void merge_sort(int a[],int t[],int lb,int ub)
// {
//     int mid=0;
//     if(lb<ub)
//     {
//         mid=(ub+lb)/2;
//         merge_sort(a,t,lb,mid);
//         merge_sort(a,t,mid+1,ub);
//         merge(a,t,lb,mid,ub);
//     }
// }

// void merge(int a[],int t[],int lb,int mid,int ub)
// {
//     int k=lb,i=lb,j=ub,le=mid;
//     while(lb<=le && mid+1<=ub)
//     {
//         if(a[lb]<a[mid+1])
//         {
//             t[k+1]=a[lb];
//             lb++;
//         }
//         else
//         {
//             t[k+1]=a[mid+1];
//             mid++;
//         }
//     }
//     while(lb<=ub)
//     {
//         t[k+1]=a[lb];
//         lb++;

//     }
//     while(mid+1<=ub)
//     {
//         t[k]=a[mid+1];
//         k++;
//         mid++;
//     }
//     for(i=0;i<=ub;i++)
//     a[i]=t[i];


// }