/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* numberOfPairs(int* nums, int numsSize, int* returnSize) {
    int* answer = (int*)malloc(2 * sizeof(int));
    answer[0] = 0;
    answer[1] = 0;
    *returnSize = 2;

    int counts[101] = {0};
    for (int i = 0; i < numsSize; i++) {
        counts[nums[i]]++;
    }

    for (int i = 0; i <= 100; i++) {
        answer[0] += counts[i] / 2;
        answer[1] += counts[i] % 2;
    }

    return answer;
}