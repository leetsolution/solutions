/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* subarrayMajority(int* nums, int numsSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    #include <stdio.h>
    #include <stdlib.h>

    int compare(const void *a, const void *b) {
        return *(int *)a - *(int *)b;
    }

    int thresholdMajorityQueries(int *nums, int numsSize, int **queries, int queriesSize, int *queriesColSize, int *ans) {
        for (int i = 0; i < queriesSize; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            int threshold = queries[i][2];
            int subSize = r - l + 1;
            int *sub = (int *)malloc(sizeof(int) * subSize);
            for (int j = 0; j < subSize; j++) {
                sub[j] = nums[l + j];
            }
            qsort(sub, subSize, sizeof(int), compare);
            int maxFreq = 0;
            int maxNum = -1;
            int currFreq = 1;
            int currNum = sub[0];
            for (int j = 1; j < subSize; j++) {
                if (sub[j] == currNum) {
                    currFreq++;
                } else {
                    if (currFreq >= threshold && (maxFreq < currFreq || (maxFreq == currFreq && currNum < maxNum))) {
                        maxFreq = currFreq;
                        maxNum = currNum;
                    }
                    currNum = sub[j];
                    currFreq = 1;
                }
            }
            if (currFreq >= threshold && (maxFreq < currFreq || (maxFreq == currFreq && currNum < maxNum))) {
                maxFreq = currFreq;
                maxNum = currNum;
            }
            ans[i] = maxNum;
            free(sub);
        }
        return 0;
    }
}