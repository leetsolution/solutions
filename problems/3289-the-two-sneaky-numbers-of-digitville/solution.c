/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getSneakyNumbers(int* nums, int numsSize, int* returnSize) {
    int count[100] = {0};
    for (int i = 0; i < numsSize; i++) {
        count[nums[i]]++;
    }
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;
    int index = 0;
    for (int i = 0; i < 100; i++) {
        if (count[i] == 2) {
            result[index++] = i;
        }
    }
    return result;
}