#include <stdio.h>

int main()
{
    int n,i,time=0,completed=0,highest;
    int at[20],bt[20],rt[20],pr[20];
    int ct[20],tat[20],wt[20];
    int visited[20]={0};

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("\nProcess P%d\n",i+1);
        printf("Arrival Time: ");
        scanf("%d",&at[i]);
        printf("Burst Time: ");
        scanf("%d",&bt[i]);
        printf("Priority: ");
        scanf("%d",&pr[i]);

        rt[i]=bt[i]; // remaining time
    }

    while(completed!=n)
    {
        highest=-1;

        for(i=0;i<n;i++)
        {
            if(at[i]<=time && rt[i]>0)
            {
                if(highest==-1 || pr[i]<pr[highest]) // smaller value = higher priority
                    highest=i;
            }
        }

        if(highest!=-1)
        {
            rt[highest]--;
            time++;

            if(rt[highest]==0)
            {
                completed++;
                ct[highest]=time;
                tat[highest]=ct[highest]-at[highest];
                wt[highest]=tat[highest]-bt[highest];
            }
        }
        else
        {
            time++;
        }
    }

    printf("\nProcess\tAT\tBT\tPR\tCT\tTAT\tWT\n");
    for(i=0;i<n;i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
        i+1,at[i],bt[i],pr[i],ct[i],tat[i],wt[i]);
    }

    return 0;
}
