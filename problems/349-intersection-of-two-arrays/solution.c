/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int *result = (int *)malloc(sizeof(int) * nums1Size);
    int k = 0;
    int *seen = (int *)calloc(1001, sizeof(int));
    for (int i = 0; i < nums1Size; i++) {
        if (seen[nums1[i]] == 0) {
            seen[nums1[i]] = 1;
        }
    }
    for (int i = 0; i < nums2Size; i++) {
        if (seen[nums2[i]] == 1) {
            result[k++] = nums2[i];
            seen[nums2[i]] = 2;
        }
    }
    *returnSize = k;
    int *finalResult = (int *)malloc(sizeof(int) * k);
    for (int i = 0; i < k; i++) {
        finalResult[i] = result[i];
    }
    free(result);
    free(seen);
    return finalResult;
}