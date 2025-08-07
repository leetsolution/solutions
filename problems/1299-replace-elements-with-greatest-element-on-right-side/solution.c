/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* replaceElements(int* arr, int arrSize, int* returnSize) {
    if (arrSize == 0) {
        *returnSize = 0;
        return arr;
    }

    int* result = (int*)malloc(arrSize * sizeof(int));
    if (result == NULL) {
        *returnSize = 0;
        return NULL;
    }

    int maxRight = -1;
    for (int i = arrSize - 1; i >= 0; i--) {
        result[i] = maxRight;
        if (arr[i] > maxRight) {
            maxRight = arr[i];
        }
    }

    *returnSize = arrSize;
    return result;
}