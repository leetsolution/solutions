/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* prefixesDivBy5(int* nums, int numsSize, int* returnSize) {
    bool* answer = (bool*)malloc(numsSize * sizeof(bool));
    *returnSize = numsSize;
    long long current_number = 0;
    for (int i = 0; i < numsSize; i++) {
        current_number = (current_number * 2 + nums[i]) % 5;
        if (current_number == 0) {
            answer[i] = true;
        } else {
            answer[i] = false;
        }
    }
    return answer;
}