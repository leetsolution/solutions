/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int* answerQueries(int* nums, int numsSize, int* queries, int queriesSize, int* returnSize) {
    qsort(nums, numsSize, sizeof(int), compare);
    int* answer = (int*)malloc(queriesSize * sizeof(int));
    *returnSize = queriesSize;

    for (int i = 0; i < queriesSize; i++) {
        int sum = 0;
        int count = 0;
        for (int j = 0; j < numsSize; j++) {
            if (sum + nums[j] <= queries[i]) {
                sum += nums[j];
                count++;
            } else {
                break;
            }
        }
        answer[i] = count;
    }

    return answer;
}