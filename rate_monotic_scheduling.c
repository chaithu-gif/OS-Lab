#include <stdio.h>
#include <math.h>

#define MAX 10

typedef struct {
    int id;
    int execution;
    int period;
    int remaining;
    int deadline;
} Task;

// GCD
int gcd(int a, int b) {
    return (b == 0) ? a : gcd(b, a % b);
}

// LCM
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

// Hyperperiod
int find_hyperperiod(Task tasks[], int n) {
    int h = tasks[0].period;
    for (int i = 1; i < n; i++) {
        h = lcm(h, tasks[i].period);
    }
    return h;
}

// Utilization check
void check_schedulability(Task tasks[], int n) {
    float U = 0;
    for (int i = 0; i < n; i++) {
        U += (float)tasks[i].execution / tasks[i].period;
    }

    float bound = n * (pow(2, (float)1/n) - 1);

    printf("\nCPU Utilization: %.3f\n", U);
    printf("RMS Bound: %.3f\n", bound);

    if (U <= bound)
        printf("Schedulable (Guaranteed by RMS)\n");
    else
        printf("Not guaranteed schedulable (but may still work)\n");
}

int main() {
    int n;
    Task tasks[MAX];

    printf("Enter number of tasks: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        tasks[i].id = i + 1;
        printf("Enter execution time and period of task %d: ", i + 1);
        scanf("%d %d", &tasks[i].execution, &tasks[i].period);
        tasks[i].remaining = 0;
        tasks[i].deadline = tasks[i].period;
    }

    check_schedulability(tasks, n);

    int hyperperiod = find_hyperperiod(tasks, n);
    printf("\nHyperperiod: %d\n", hyperperiod);

    printf("\n===== GANTT CHART =====\n");

    for (int t = 0; t < hyperperiod; t++) {

        // Release new tasks
        for (int i = 0; i < n; i++) {
            if (t % tasks[i].period == 0) {
                tasks[i].remaining = tasks[i].execution;
                tasks[i].deadline = t + tasks[i].period;
            }
        }

        // Deadline check
        for (int i = 0; i < n; i++) {
            if (tasks[i].remaining > 0 && t >= tasks[i].deadline) {
                printf("\nDeadline Miss: Task T%d at time %d\n", tasks[i].id, t);
                return 0;
            }
        }

        // Select highest priority task (smallest period)
        int highest = -1;
        for (int i = 0; i < n; i++) {
            if (tasks[i].remaining > 0) {
                if (highest == -1 || tasks[i].period < tasks[highest].period) {
                    highest = i;
                }
            }
        }

        // Execute
        if (highest != -1) {
            printf("| T%d ", tasks[highest].id);
            tasks[highest].remaining--;
        } else {
            printf("| Idle ");
        }
    }

    printf("|\n");
    printf("=======================\n");

    return 0;
}
