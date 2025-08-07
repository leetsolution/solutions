/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* createTargetArray(int* nums, int numsSize, int* index, int indexSize, int* returnSize) {
    int* target = (int*)malloc(sizeof(int) * numsSize);
    *returnSize = 0;
    for (int i = 0; i < numsSize; i++) {
        int idx = index[i];
        if (idx == *returnSize) {
            target[*returnSize] = nums[i];
            (*returnSize)++;
        } else {
            for (int j = *returnSize; j > idx; j--) {
                target[j] = target[j - 1];
            }
            target[idx] = nums[i];
            (*returnSize)++;
        }
    }
    return target;
}