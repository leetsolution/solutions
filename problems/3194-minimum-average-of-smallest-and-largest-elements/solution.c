#include <float.h>
#include <stdlib.h>

double minimumAverage(int* nums, int numsSize) {
    double averages[numsSize / 2];
    int averagesSize = 0;

    int* sortedNums = (int*)malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        sortedNums[i] = nums[i];
    }

    qsort(sortedNums, numsSize, sizeof(int), [](const void* a, const void* b) {
        return (*(int*)a - *(int*)b);
    });

    for (int i = 0; i < numsSize / 2; i++) {
        averages[i] = (double)(sortedNums[i] + sortedNums[numsSize - 1 - i]) / 2.0;
        averagesSize++;
    }

    double minAverage = DBL_MAX;
    for (int i = 0; i < averagesSize; i++) {
        if (averages[i] < minAverage) {
            minAverage = averages[i];
        }
    }

    free(sortedNums);
    return minAverage;
}