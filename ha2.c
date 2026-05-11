#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void merge(int a[], int low, int mid, int high)
{
    int b[100], i, j, k;

    i = low;
    j = mid + 1;
    k = low;

    while(i <= mid && j <= high)
    {
        if(a[i] < a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }

    while(i <= mid)
        b[k++] = a[i++];

    while(j <= high)
        b[k++] = a[j++];

    for(i = low; i <= high; i++)
        a[i] = b[i];
}

void mergesort(int a[], int low, int high)
{
    int mid;

    if(low < high)
    {
        mid = (low + high) / 2;

        mergesort(a, low, mid);
        mergesort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

int main()
{
    int a[100], n, i;
    clock_t end,st;

    printf("Enter number of elements: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
        a[i]=rand()/50;
    printf("\n the array before sorting is:");

        scanf("%d", &a[i]);

    mergesort(a, 0, n-1);
    end=clock();

    printf("Sorted elements:\n");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);
    d=(float)(end-st)CLOCKS_PER_SEC;
    printf("\ntime taken is %fsec",d);

    return 0;
}
