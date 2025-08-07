/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* minSubsequence(int* nums, int numsSize, int* returnSize) {
    int totalSum = 0;
    for (int i = 0; i < numsSize; i++) {
        totalSum += nums[i];
    }

    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = 0; j < numsSize - i - 1; j++) {
            if (nums[j] < nums[j + 1]) {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }

    int currentSum = 0;
    int* result = (int*)malloc(numsSize * sizeof(int));
    *returnSize = 0;

    for (int i = 0; i < numsSize; i++) {
        result[(*returnSize)++] = nums[i];
        currentSum += nums[i];
        if (currentSum > totalSum - currentSum) {
            return result;
        }
    }

    return result;
}