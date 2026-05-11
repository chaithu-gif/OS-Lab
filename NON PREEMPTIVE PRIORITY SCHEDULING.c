#include <stdio.h>

int main()
{
    int n,i,j;
    int at[20],bt[20],pr[20];
    int ct[20],tat[20],wt[20];
    int completed[20]={0};

    int time=0,done=0,max,pos;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("Enter AT BT Priority for P%d: ",i+1);
        scanf("%d%d%d",&at[i],&bt[i],&pr[i]);
    }

    while(done<n)
    {
        max=-1;
        pos=-1;

        for(i=0;i<n;i++)
        {
            if(at[i]<=time && completed[i]==0)
            {
                if(pr[i]>max)
                {
                    max=pr[i];
                    pos=i;
                }
            }
        }

        if(pos!=-1)
        {
            time=time+bt[pos];
            ct[pos]=time;

            tat[pos]=ct[pos]-at[pos];
            wt[pos]=tat[pos]-bt[pos];

            completed[pos]=1;
            done++;
        }
        else
        {
            time++;
        }
    }

    float avgwt=0,avgtat=0;

    printf("\nP\tAT\tBT\tPR\tCT\tTAT\tWT\n");

    for(i=0;i<n;i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
        i+1,at[i],bt[i],pr[i],ct[i],tat[i],wt[i]);

        avgwt+=wt[i];
        avgtat+=tat[i];
    }

    printf("\nAverage WT = %.2f",avgwt/n);
    printf("\nAverage TAT = %.2f",avgtat/n);

    return 0;
}
