/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* popcountDepth(long long* nums, int numsSize, long long** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    #include <stdio.h>
    #include <stdlib.h>

    int popcount(long long n) {
        int count = 0;
        while (n > 0) {
            count += n & 1;
            n >>= 1;
        }
        return count;
    }

    int popcount_depth(long long n) {
        int depth = 0;
        while (n != 1) {
            n = popcount(n);
            depth++;
        }
        return depth;
    }

    int* solve(long long* nums, int numsSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
        int* answer = (int*)malloc(queriesSize * sizeof(int));
        *returnSize = queriesSize;

        for (int i = 0; i < queriesSize; i++) {
            if (queries[i][0] == 1) {
                int count = 0;
                int l = queries[i][1];
                int r = queries[i][2];
                int k = queries[i][3];
                for (int j = l; j <= r; j++) {
                    if (popcount_depth(nums[j]) == k) {
                        count++;
                    }
                }
                answer[i] = count;
            } else {
                int idx = queries[i][1];
                long long val = queries[i][2];
                nums[idx] = val;
            }
        }

        return answer;
    }
}