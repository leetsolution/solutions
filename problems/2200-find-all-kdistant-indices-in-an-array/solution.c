/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findKDistantIndices(int* nums, int numsSize, int key, int k, int* returnSize) {
    int *result = (int *)malloc(numsSize * sizeof(int));
    int count = 0;
    int *keyIndices = (int *)malloc(numsSize * sizeof(int));
    int keyCount = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == key) {
            keyIndices[keyCount++] = i;
        }
    }
    for (int i = 0; i < numsSize; i++) {
        int isKDistant = 0;
        for (int j = 0; j < keyCount; j++) {
            if (abs(i - keyIndices[j]) <= k) {
                isKDistant = 1;
                break;
            }
        }
        if (isKDistant) {
            result[count++] = i;
        }
    }
    *returnSize = count;
    int *finalResult = (int *)malloc(count * sizeof(int));
    for (int i = 0; i < count; i++) {
        finalResult[i] = result[i];
    }
    free(result);
    free(keyIndices);
    return finalResult;
}