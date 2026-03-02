#include<stdio.h>
int main(){
    int n,wt[20],at[20],ct[20],bt[20],tat[20];
    float twt=0.0,ttat=0.0,awt,att;
    printf("\n enter the number of processess:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("\n enter arrival time for process:%d:",i+1);
        scanf("%d",&at[i]);
        printf("\n enter burst time for process:%d:",i+1);
        scanf("%d",&bt[i]);
    }
    ct[0]=at[0]+bt[0];
    wt[0]=0;
    tat[0]=bt[0];
    for (int i = 1; i< n; i++) {
        if (ct[i - 1] < at[i]) {
            ct[i] = at[i] + bt[i]; // CPU idle
            wt[i] = 0;
        } else {
            wt[i] = ct[i - 1] - at[i];
            ct[i] = ct[i - 1] + bt[i];
        }
        tat[i] = wt[i] + bt[i];
    }
    for(int i=0;i<n;i++){
        twt+=wt[i];
        ttat+=tat[i];
    }
    awt=twt/n;
    att=ttat/n;
    printf("\nPROCESS\tAT\tBT\tCT\tWT\tTAT");
    for(int i=0;i<n;i++){
        printf("\nP%d\t%d\t%d\t%d\t%d\t%d",i+1,at                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          [i],bt[i],ct[i],wt[i],tat[i]);
    }
    printf("\n\n average waiting time=%.2f",awt);
    printf("\n\n average turn around time =%.2f",att);
    return 0;

}
