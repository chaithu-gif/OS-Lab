#include <stdio.h>

#define MAX 10

typedef struct {
    int id;
    int weight;
    int remaining_share;
} Task;

int main() {
    int n, total_weight = 0, time_units;

    Task tasks[MAX];

    printf("Enter number of tasks: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        tasks[i].id = i + 1;
        printf("Enter weight of task %d: ", i + 1);
        scanf("%d", &tasks[i].weight);
        total_weight += tasks[i].weight;
    }

    printf("Enter total time units to simulate: ");
    scanf("%d", &time_units);

    // Assign proportional slots
    for (int i = 0; i < n; i++) {
        tasks[i].remaining_share = (tasks[i].weight * time_units) / total_weight;
    }

    printf("\n===== PROPORTIONAL SCHEDULING =====\n");

    for (int t = 0; t < time_units; t++) {
        int executed = 0;

        for (int i = 0; i < n; i++) {
            if (tasks[i].remaining_share > 0) {
                printf("| T%d ", tasks[i].id);
                tasks[i].remaining_share--;
                executed = 1;
                break;
            }
        }

        if (!executed)
            printf("| Idle ");
    }

    printf("|\n===============================\n");

    return 0;
}

