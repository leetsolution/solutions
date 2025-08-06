int minRemoval(int* nums, int numsSize, int k) {
    #include <stdio.h>
    #include <stdlib.h>

    int cmp(const void *a, const void *b) {
        return *(int *)a - *(int *)b;
    }

    int minimumRemovals(int *nums, int numsSize, int k) {
        qsort(nums, numsSize, sizeof(int), cmp);
        int minRemovals = numsSize - 1;
        for (int i = 0; i < numsSize; i++) {
            for (int j = i; j < numsSize; j++) {
                if (nums[j] <= nums[i] * k) {
                    int removals = numsSize - (j - i + 1);
                    if (removals < minRemovals) {
                        minRemovals = removals;
                    }
                } else {
                    break;
                }
            }
        }
        return minRemovals;
    }
}