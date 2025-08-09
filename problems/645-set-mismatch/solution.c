/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findErrorNums(int* nums, int numsSize, int* returnSize) {
    int *result = (int *)malloc(2 * sizeof(int));
    *returnSize = 2;
    long long sum = 0;
    long long expectedSum = (long long)numsSize * (numsSize + 1) / 2;
    int freq[10001] = {0};
    int duplicate = 0;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
        freq[nums[i]]++;
        if (freq[nums[i]] == 2) {
            duplicate = nums[i];
        }
    }
    result[0] = duplicate;
    result[1] = expectedSum - sum + duplicate;
    return result;
}