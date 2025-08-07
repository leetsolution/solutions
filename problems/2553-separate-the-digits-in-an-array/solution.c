/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* separateDigits(int* nums, int numsSize, int* returnSize) {
    int count = 0;
    for (int i = 0; i < numsSize; i++) {
        int num = nums[i];
        int temp = num;
        while (temp > 0) {
            count++;
            temp /= 10;
        }
    }
    int* result = (int*)malloc(count * sizeof(int));
    *returnSize = count;
    int index = 0;
    for (int i = 0; i < numsSize; i++) {
        int num = nums[i];
        int temp = num;
        while (temp > 0) {
            result[index++] = temp % 10;
            temp /= 10;
        }
    }
    return result;
}