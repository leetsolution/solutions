/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** summaryRanges(int* nums, int numsSize, int* returnSize) {
    if (numsSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    char **result = (char **)malloc(numsSize * sizeof(char *));
    *returnSize = 0;
    int start = nums[0];
    int end = nums[0];

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == end + 1) {
            end = nums[i];
        } else {
            char *range = (char *)malloc(20 * sizeof(char)); 
            if (start == end) {
                sprintf(range, "%d", start);
            } else {
                sprintf(range, "%d->%d", start, end);
            }
            result[(*returnSize)++] = range;
            start = nums[i];
            end = nums[i];
        }
    }

    char *range = (char *)malloc(20 * sizeof(char));
    if (start == end) {
        sprintf(range, "%d", start);
    } else {
        sprintf(range, "%d->%d", start, end);
    }
    result[(*returnSize)++] = range;

    return result;
}