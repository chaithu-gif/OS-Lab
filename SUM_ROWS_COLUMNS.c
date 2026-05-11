#include<stdio.h>

int main()
{
    int a[10][10],r,c,i,j,sum;

    printf("Enter rows and columns: ");
    scanf("%d%d",&r,&c);

    printf("Enter matrix:\n");

    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            scanf("%d",&a[i][j]);

    printf("\nRow sums:\n");

    for(i=0;i<r;i++)
    {
        sum=0;
        for(j=0;j<c;j++)
            sum+=a[i][j];

        printf("Row %d = %d\n",i+1,sum);
    }

    printf("\nColumn sums:\n");

    for(j=0;j<c;j++)
    {
        sum=0;
        for(i=0;i<r;i++)
            sum+=a[i][j];

        printf("Column %d = %d\n",j+1,sum);
    }
}
