// Deadlock Detection Algorithm in C
#include <stdio.h>

int main() {

    int n, m, i, j, k;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resource types: ");
    scanf("%d", &m);

    int alloc[n][m], request[n][m];
    int avail[m], work[m];
    int finish[n];

    // Allocation Matrix
    printf("\nEnter Allocation Matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }

    // Request Matrix
    printf("\nEnter Request Matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            scanf("%d", &request[i][j]);
        }
    }

    // Available Resources
    printf("\nEnter Available Resources:\n");
    for(i = 0; i < m; i++) {
        scanf("%d", &avail[i]);
        work[i] = avail[i];
    }

    // Initialize Finish Array
    for(i = 0; i < n; i++) {

        int flag = 0;

        for(j = 0; j < m; j++) {
            if(alloc[i][j] != 0) {
                flag = 1;
                break;
            }
        }

        if(flag)
            finish[i] = 0;
        else
            finish[i] = 1;
    }

    int found, deadlock = 0;

    printf("\nWork = (%d ", work[0]);

    for(i = 1; i < m; i++)
        printf("%d ", work[i]);

    printf(")\n");

    while(1) {

        found = 0;

        for(i = 0; i < n; i++) {

            if(finish[i] == 0) {

                for(j = 0; j < m; j++) {

                    if(request[i][j] > work[j])
                        break;
                }

                // Process can execute
                if(j == m) {

                    printf("\nP%d is selected\n", i);

                    printf("Work = Work + Allocation%d\n", i);

                    for(k = 0; k < m; k++) {
                        work[k] += alloc[i][k];
                    }

                    printf("New Work = (");

                    for(k = 0; k < m; k++) {
                        printf("%d ", work[k]);
                    }

                    printf(")\n");

                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if(found == 0)
            break;
    }

    printf("\n");

    for(i = 0; i < n; i++) {

        if(finish[i] == 0) {
            printf("P%d is DEADLOCKED\n", i);
            deadlock = 1;
        }
    }

    if(deadlock == 0)
        printf("NO DEADLOCK DETECTED\n");

    return 0;
}
