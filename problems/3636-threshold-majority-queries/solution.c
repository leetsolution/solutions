/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* subarrayMajority(int* nums, int numsSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    #include <stdio.h>
    #include <stdlib.h>

    int cmpfunc (const void * a, const void * b) {
       return ( *(int*)a - *(int*)b );
    }

    int* majorityElement(int* nums, int numsSize, int* queries, int queriesSize, int** colSizes, int* returnSize){
        *returnSize = queriesSize;
        int *ans = (int *)malloc(queriesSize * sizeof(int));
        for(int i=0; i<queriesSize; ++i){
            int l = queries[i*3];
            int r = queries[i*3+1];
            int threshold = queries[i*3+2];
            int subSize = r - l + 1;
            int *subNums = (int *)malloc(subSize * sizeof(int));
            for(int j=0; j<subSize; ++j){
                subNums[j] = nums[l+j];
            }
            qsort(subNums, subSize, sizeof(int), cmpfunc);
            int maxCount = 0;
            int maxElem = -1;
            int count = 1;
            for(int j=1; j<subSize; ++j){
                if(subNums[j] == subNums[j-1]){
                    count++;
                } else {
                    if(count >= threshold && count > maxCount){
                        maxCount = count;
                        maxElem = subNums[j-1];
                    } else if (count >= threshold && count == maxCount && subNums[j-1] < maxElem){
                        maxElem = subNums[j-1];
                    }
                    count = 1;
                }
            }
            if(count >= threshold && count > maxCount){
                maxCount = count;
                maxElem = subNums[subSize-1];
            } else if (count >= threshold && count == maxCount && subNums[subSize-1] < maxElem){
                maxElem = subNums[subSize-1];
            }
            ans[i] = maxElem;
            free(subNums);
        }
        return ans;
    }
}