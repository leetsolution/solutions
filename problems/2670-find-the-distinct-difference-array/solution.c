/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* distinctDifferenceArray(int* nums, int numsSize, int* returnSize) {
    int* diff = (int*)malloc(numsSize * sizeof(int));
    *returnSize = numsSize;

    for (int i = 0; i < numsSize; i++) {
        int prefix_distinct = 0;
        int suffix_distinct = 0;

        int prefix_set[51] = {0};
        int suffix_set[51] = {0};

        for (int j = 0; j <= i; j++) {
            if (prefix_set[nums[j]] == 0) {
                prefix_distinct++;
                prefix_set[nums[j]] = 1;
            }
        }

        for (int j = i + 1; j < numsSize; j++) {
            if (suffix_set[nums[j]] == 0) {
                suffix_distinct++;
                suffix_set[nums[j]] = 1;
            }
        }

        diff[i] = prefix_distinct - suffix_distinct;
    }

    return diff;
}