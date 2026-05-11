#include <stdio.h>
#include <stdlib.h>

int mutex = 1;
int full = 0;
int empty;

int *buffer;
int size;

int in = 0, out = 0;

// wait function
void wait() {
    mutex--;
}

// signal function
void signal() {
    mutex++;
}

// producer
void producer() {
    if (mutex == 1 && empty != 0) {
        wait();

        int item;
        printf("Enter item to produce: ");
        scanf("%d", &item);

        buffer[in] = item;        printf("Produced: %d at index %d\n", item, in);

        in = (in + 1) % size;
        full++;
        empty--;

        signal();
    } else {
        printf("Buffer is full!\n");
    }
}

// consumer
void consumer() {
    if (mutex == 1 && full != 0) {
        wait();

        int item = buffer[out];
        printf("Consumed: %d from index %d\n", item, out);

        out = (out + 1) % size;
        full--;
        empty++;

        signal();
    } else {
        printf("Buffer is empty!\n");
    }
}

int main() {
    int choice;
    int running = 1;

    printf("Enter buffer size: ");
    if (scanf("%d", &size) != 1 || size <= 0) {
        printf("Invalid buffer size!\n");
        return 0;
    }

    buffer = (int*)malloc(size * sizeof(int));
    empty = size;

    while (running) {
        printf("\n1. Producer  2. Consumer  3. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Exiting...\n");
            break;
        }

        switch (choice) {
            case 1:
                producer();
                break;

            case 2:
                consumer();
                break;

            case 3:
                running = 0;
                break;

            default:
                printf("Invalid choice!\n");
        }

        // Debug (optional)
        printf("Buffer State → full: %d, empty: %d, in: %d, out: %d\n",
               full, empty, in, out);
    }

    free(buffer);
    return 0;
}
