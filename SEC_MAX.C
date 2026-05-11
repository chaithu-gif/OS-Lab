#include<stdio.h>

int main()
{
    int n,i;
    int a[100];
    int smallest, second;

    printf("Enter number of elements: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    smallest=second=9999;

    for(i=0;i<n;i++)
    {
        if(a[i] < smallest)
        {
            second = smallest;
            smallest = a[i];
        }
        else if(a[i] < second && a[i] != smallest)
        {
            second = a[i];
        }
    }

    printf("Second smallest = %d",second);
}
