#include <stdio.h>
#include <stdlib.h>

int n, h;
int pos[20];
int eaten[20] = {0};

// check if neighbors are eating
int canEat(int p) {
    for (int i = 0; i < h; i++) {
        if (pos[i] == p) {
            int left = (p == 1) ? n : p - 1;
            int right = (p == n) ? 1 : p + 1;

            for (int j = 0; j < h; j++) {
                if (!eaten[j] && (pos[j] == left || pos[j] == right)) {
                    return 0;
                }
            }
        }
    }
    return 1;
}

void oneAtATime() {
    printf("\nAllow one philosopher to eat at any time\n");

    for (int i = 0; i < h; i++) eaten[i] = 0;

    for (int i = 0; i < h; i++) {
        printf("P %d is waiting\n", pos[i]);
    }

    for (int i = 0; i < h; i++) {
        printf("P %d is granted to eat\n", pos[i]);
        printf("P %d has finished eating\n", pos[i]);
    }
}

void twoAtATime() {
    printf("\nAllow two philosophers to eat at a time\n");

    for (int i = 0; i < h; i++) eaten[i] = 0;

    int count = 0;

    while (count < h) {
        for (int i = 0; i < h; i++) {
            if (!eaten[i] && canEat(pos[i])) {

                printf("P %d is granted to eat\n", pos[i]);
                eaten[i] = 1;
                count++;

                // allow only 2 at a time
                int tempCount = 1;

                for (int j = i + 1; j < h && tempCount < 2; j++) {
                    if (!eaten[j] && canEat(pos[j])) {
                        printf("P %d is granted to eat\n", pos[j]);
                        eaten[j] = 1;
                        count++;
                        tempCount++;
                    }
                }

                // mark finished
                for (int k = 0; k < h; k++) {
                    if (eaten[k]) {
                        printf("P %d has finished eating\n", pos[k]);
                    }
                }
                break;
            }
        }
    }
}

int main() {
    int choice;

    printf("Enter the total number of philosophers: ");
    scanf("%d", &n);

    printf("How many are hungry: ");
    scanf("%d", &h);

    for (int i = 0; i < h; i++) {
        printf("Enter philosopher %d position (1 to %d): ", i + 1, n);
        scanf("%d", &pos[i]);
    }

    while (1) {
        printf("\n1. One can eat at a time\n");
        printf("2. Two can eat at a time\n");
        printf("3. Exit\n");                                                                                                                                                                                        
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                oneAtATime();
                break;

            case 2:
                twoAtATime();
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
