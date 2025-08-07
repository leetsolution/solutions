#include <stdio.h>
#include <stdlib.h>

int minimumBoxes(int* apple, int appleSize, int* capacity, int capacitySize) {
    int totalApples = 0;
    for (int i = 0; i < appleSize; i++) {
        totalApples += apple[i];
    }

    int* sortedCapacity = (int*)malloc(capacitySize * sizeof(int));
    for (int i = 0; i < capacitySize; i++) {
        sortedCapacity[i] = capacity[i];
    }

    for (int i = 0; i < capacitySize - 1; i++) {
        for (int j = 0; j < capacitySize - i - 1; j++) {
            if (sortedCapacity[j] < sortedCapacity[j + 1]) {
                int temp = sortedCapacity[j];
                sortedCapacity[j] = sortedCapacity[j + 1];
                sortedCapacity[j + 1] = temp;
            }
        }
    }

    int boxesUsed = 0;
    int currentCapacity = 0;
    for (int i = 0; i < capacitySize; i++) {
        currentCapacity += sortedCapacity[i];
        boxesUsed++;
        if (currentCapacity >= totalApples) {
            free(sortedCapacity);
            return boxesUsed;
        }
    }

    free(sortedCapacity);
    return boxesUsed;
}