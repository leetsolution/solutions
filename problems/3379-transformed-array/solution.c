/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* constructTransformedArray(int* nums, int numsSize, int* returnSize) {
    int* result = (int*)malloc(numsSize * sizeof(int));
    *returnSize = numsSize;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > 0) {
            int next_index = (i + nums[i]) % numsSize;
            if (next_index < 0)
                next_index += numsSize;
            result[i] = nums[next_index];
        } else if (nums[i] < 0) {
            int next_index = (i + nums[i]) % numsSize;
            if (next_index < 0)
                next_index += numsSize;
            result[i] = nums[next_index];
        } else {
            result[i] = nums[i];
        }
    }

    return result;
}