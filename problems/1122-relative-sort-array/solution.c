/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize) {
    int* result = (int*)malloc(arr1Size * sizeof(int));
    int* counts = (int*)calloc(1001, sizeof(int));
    int index = 0;

    for (int i = 0; i < arr1Size; i++) {
        counts[arr1[i]]++;
    }

    for (int i = 0; i < arr2Size; i++) {
        while (counts[arr2[i]] > 0) {
            result[index++] = arr2[i];
            counts[arr2[i]]--;
        }
    }

    for (int i = 0; i < 1001; i++) {
        while (counts[i] > 0) {
            result[index++] = i;
            counts[i]--;
        }
    }

    free(counts);
    *returnSize = arr1Size;
    return result;
}