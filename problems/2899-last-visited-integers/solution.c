/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* lastVisitedIntegers(int* nums, int numsSize, int* returnSize) {
    int* seen = (int*)malloc(numsSize * sizeof(int));
    int seenSize = 0;
    int* ans = (int*)malloc(numsSize * sizeof(int));
    int ansSize = 0;
    int k = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > 0) {
            for (int j = seenSize; j > 0; j--) {
                seen[j] = seen[j - 1];
            }
            seen[0] = nums[i];
            seenSize++;
            k = 0;
        } else {
            k++;
            if (k <= seenSize) {
                ans[ansSize++] = seen[k - 1];
            } else {
                ans[ansSize++] = -1;
            }
        }
    }

    *returnSize = ansSize;
    free(seen);
    return ans;
}