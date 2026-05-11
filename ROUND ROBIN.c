#include <stdio.h>

int main()
{
    int n, tq;
    int at[20], bt[20], rt[20];
    int ct[20], tat[20], wt[20];
    int i, time = 0, remain, flag = 0;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    remain = n;

    for(i=0;i<n;i++)
    {
        printf("\nProcess P%d\n",i+1);
        printf("Arrival Time: ");
        scanf("%d",&at[i]);

        printf("Burst Time: ");
        scanf("%d",&bt[i]);

        rt[i] = bt[i];
    }

    printf("\nEnter Time Quantum: ");
    scanf("%d",&tq);

    while(remain != 0)
    {
        for(i=0;i<n;i++)
        {
            if(rt[i] > 0 && at[i] <= time)
            {
                if(rt[i] <= tq)
                {
                    time += rt[i];
                    rt[i] = 0;
                    ct[i] = time;
                    remain--;
                }
                else
                {
                    rt[i] -= tq;
                    time += tq;
                }
            }
        }
    }

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");

    for(i=0;i<n;i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
        i+1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    return 0;
}
