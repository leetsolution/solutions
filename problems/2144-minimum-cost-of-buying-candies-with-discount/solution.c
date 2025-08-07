#include <stdio.h>
#include <stdlib.h>

int minimumCost(int* cost, int costSize) {
    if (costSize <= 0) return 0;

    int n = costSize;
    int i, j;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (cost[j] < cost[j + 1]) {
                int temp = cost[j];
                cost[j] = cost[j + 1];
                cost[j + 1] = temp;
            }
        }
    }

    int totalCost = 0;
    for (i = 0; i < n; i++) {
        if ((i + 1) % 3 != 0) {
            totalCost += cost[i];
        }
    }

    return totalCost;
}