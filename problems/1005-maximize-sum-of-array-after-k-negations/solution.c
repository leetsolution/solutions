#include <stdio.h>
#include <stdlib.h>

int largestSumAfterKNegations(int* nums, int numsSize, int k) {
    int i, j, minIndex;
    for (i = 0; i < k; i++) {
        minIndex = 0;
        for (j = 1; j < numsSize; j++) {
            if (nums[j] < nums[minIndex]) {
                minIndex = j;
            }
        }
        nums[minIndex] = -nums[minIndex];
    }
    int sum = 0;
    for (i = 0; i < numsSize; i++) {
        sum += nums[i];
    }
    return sum;
}