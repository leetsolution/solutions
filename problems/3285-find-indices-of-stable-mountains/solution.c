/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* stableMountains(int* height, int heightSize, int threshold, int* returnSize) {
    int* result = (int*)malloc(heightSize * sizeof(int));
    *returnSize = 0;
    for (int i = 1; i < heightSize; i++) {
        if (height[i - 1] > threshold) {
            result[(*returnSize)++] = i;
        }
    }
    int* finalResult = (int*)malloc((*returnSize) * sizeof(int));
    for (int i = 0; i < *returnSize; i++) {
        finalResult[i] = result[i];
    }
    free(result);
    return finalResult;
}