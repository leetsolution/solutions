/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    int *result = (int *)malloc(numsSize * sizeof(int));
    *returnSize = 0;
    int i;
    for (i = 0; i < numsSize; i++) {
        int index = abs(nums[i]) - 1;
        if (nums[index] > 0) {
            nums[index] = -nums[index];
        }
    }
    for (i = 0; i < numsSize; i++) {
        if (nums[i] > 0) {
            result[(*returnSize)++] = i + 1;
        }
    }
    int *finalResult = (int *)malloc((*returnSize) * sizeof(int));
    for(i = 0; i < *returnSize; i++){
        finalResult[i] = result[i];
    }
    free(result);
    return finalResult;
}