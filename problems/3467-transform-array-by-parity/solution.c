/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* transformArray(int* nums, int numsSize, int* returnSize) {
    int* transformedNums = (int*)malloc(numsSize * sizeof(int));
    *returnSize = numsSize;
    
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] % 2 == 0) {
            transformedNums[i] = 0;
        } else {
            transformedNums[i] = 1;
        }
    }
    
    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = 0; j < numsSize - i - 1; j++) {
            if (transformedNums[j] > transformedNums[j + 1]) {
                int temp = transformedNums[j];
                transformedNums[j] = transformedNums[j + 1];
                transformedNums[j + 1] = temp;
            }
        }
    }
    
    return transformedNums;
}