#include <stdio.h>

// Function to display frames
void display(int frames[], int f) {
    for (int i = 0; i < f; i++) {
        if (frames[i] == -1)
            printf("- ");
        else
            printf("%d ", frames[i]);
    }
    printf("\n");
}

// FIFO Algorithm
void FIFO(int pages[], int n, int f) {
    int frames[f], front = 0, faults = 0, found;

    for (int i = 0; i < f; i++)
        frames[i] = -1;

    printf("\nFIFO Page Replacement Process:\n");

    for (int i = 0; i < n; i++) {
        found = 0;

        for (int j = 0; j < f; j++) {
            if (frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        if (!found) {
            frames[front] = pages[i];
            front = (front + 1) % f;
            faults++;

            printf("PF No. %d: ", faults);
            display(frames, f);
        }
    }

    printf("FIFO Page Faults: %d\n", faults);
}

// LRU Algorithm
void LRU(int pages[], int n, int f) {
    int frames[f], time[f];
    int faults = 0, count = 0, found;

    for (int i = 0; i < f; i++) {
        frames[i] = -1;
        time[i] = 0;
    }

    printf("\nLRU Page Replacement Process:\n");

    for (int i = 0; i < n; i++) {
        found = 0;

        for (int j = 0; j < f; j++) {
            if (frames[j] == pages[i]) {
                count++;
                time[j] = count;
                found = 1;
                break;
            }
        }

        if (!found) {
            int pos = 0;

            for (int j = 1; j < f; j++) {
                if (time[j] < time[pos])
                    pos = j;
            }

            frames[pos] = pages[i];
            count++;
            time[pos] = count;
            faults++;

            printf("PF No. %d: ", faults);
            display(frames, f);
        }
    }

    printf("LRU Page Faults: %d\n", faults);
}

// Optimal Algorithm
void Optimal(int pages[], int n, int f) {
    int frames[f];
    int faults = 0, found;

    for (int i = 0; i < f; i++)
        frames[i] = -1;

    printf("\nOptimal Page Replacement Process:\n");

    for (int i = 0; i < n; i++) {
        found = 0;

        for (int j = 0; j < f; j++) {
            if (frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        if (!found) {
            int pos = -1, farthest = i + 1;

            // Empty frame check
            for (int j = 0; j < f; j++) {
                if (frames[j] == -1) {
                    pos = j;
                    break;
                }
            }

            // Find optimal page to replace
            if (pos == -1) {
                int max = -1;

                for (int j = 0; j < f; j++) {
                    int k;

                    for (k = i + 1; k < n; k++) {
                        if (frames[j] == pages[k])
                            break;
                    }

                    if (k > max) {
                        max = k;
                        pos = j;
                    }
                }
            }

            frames[pos] = pages[i];
            faults++;

            printf("PF No. %d: ", faults);
            display(frames, f);
        }
    }

    printf("Optimal Page Faults: %d\n", faults);
}

int main() {
    int f, n;

    printf("Enter the number of Frames: ");
    scanf("%d", &f);

    printf("Enter the length of reference string: ");
    scanf("%d", &n);

    int pages[n];

    printf("Enter the reference string: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    FIFO(pages, n, f);
    LRU(pages, n, f);
    Optimal(pages, n, f);

    return 0;
}
