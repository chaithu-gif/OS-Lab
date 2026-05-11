#include<stdio.h>

int main(){
    int n,i;
    int pid[20],at[20],bt[20],rt[20],wt[20],tat[20],ct[20];
    int completed[20]={0};
    int time=0,count=0,shortest;
    int twt=0,ttat=0;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        pid[i]=i+1;
        printf("Arrival time P%d: ",i+1);
        scanf("%d",&at[i]);
        printf("Burst time P%d: ",i+1);
        scanf("%d",&bt[i]);
        rt[i]=bt[i];  // initialize remaining time
    }

    while(count<n){
        shortest=-1;

        // Find process with shortest remaining time among arrived
        for(i=0;i<n;i++){
            if(at[i]<=time && completed[i]==0){
                if(shortest==-1 || rt[i]<rt[shortest])
                    shortest=i;
            }
        }

        if(shortest==-1){
            time++;  // no process has arrived yet
        }
        else{
            rt[shortest]--; // run for 1 unit
            time++;

            if(rt[shortest]==0){ // process finished
                ct[shortest]=time;
                tat[shortest]=ct[shortest]-at[shortest];
                wt[shortest]=tat[shortest]-bt[shortest];
                completed[shortest]=1;
                count++;
            }
        }
    }

    printf("\nPID\tAT\tBT\tWT\tTAT\n");
    for(i=0;i<n;i++){
        printf("P%d\t%d\t%d\t%d\t%d\n",pid[i],at[i],bt[i],wt[i],tat[i]);
        twt+=wt[i];
        ttat+=tat[i];
    }

    printf("\nAverage WT = %.2f",(float)twt/n);
    printf("\nAverage TAT = %.2f",(float)ttat/n);

    return 0;
}
