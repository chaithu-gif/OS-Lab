#include <stdio.h>

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

    int hyperperiod = find_hyperperiod(tasks, n);
    printf("\nHyperperiod: %d\n", hyperperiod);

    printf("\n===== EDF GANTT CHART =====\n");

    for (int t = 0; t < hyperperiod; t++) {

        // Release tasks
        for (int i = 0; i < n; i++) {
            if (t % tasks[i].period == 0) {
                tasks[i].remaining = tasks[i].execution;
                tasks[i].deadline = t + tasks[i].period;
            }
        }

        // Check deadline miss
        for (int i = 0; i < n; i++) {
            if (tasks[i].remaining > 0 && t >= tasks[i].deadline) {
                printf("\nDeadline Miss: T%d at time %d\n", tasks[i].id, t);
                return 0;
            }
        }

        // Select earliest deadline
        int earliest = -1;
        for (int i = 0; i < n; i++) {
            if (tasks[i].remaining > 0) {
                if (earliest == -1 || tasks[i].deadline < tasks[earliest].deadline) {
                    earliest = i;
                }
            }
        }

        // Execute
        if (earliest != -1) {
            printf("| T%d ", tasks[earliest].id);
            tasks[earliest].remaining--;
        } else {
            printf("| Idle ");
        }
    }

    printf("|\n===========================\n");

    return 0;
}
