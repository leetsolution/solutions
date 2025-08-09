#include <stdio.h>
#include <stdlib.h>

int minRemoval(int* nums, int numsSize, int k) {
    if (numsSize <= 1) {
        return 0;
    }

    qsort(nums, numsSize, sizeof(int), (int (*)(const void *, const void *))compare);

    int max_len = 0;
    for (int i = 0; i < numsSize; i++) {
        int current_len = 0;
        for (int j = i; j < numsSize; j++) {
            if ((long long)nums[j] <= (long long)nums[i] * k) {
                current_len++;
            } else {
                break;
            }
        }
        if (current_len > max_len) {
            max_len = current_len;
        }
    }

    return numsSize - max_len;
}

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}