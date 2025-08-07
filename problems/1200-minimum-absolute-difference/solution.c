/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int** minimumAbsDifference(int* arr, int arrSize, int* returnSize, int** returnColumnSizes) {
    qsort(arr, arrSize, sizeof(int), compare);

    int minDiff = INT_MAX;
    for (int i = 0; i < arrSize - 1; i++) {
        int diff = arr[i + 1] - arr[i];
        if (diff < minDiff) {
            minDiff = diff;
        }
    }

    int count = 0;
    for (int i = 0; i < arrSize - 1; i++) {
        if (arr[i + 1] - arr[i] == minDiff) {
            count++;
        }
    }

    int** result = (int**)malloc(count * sizeof(int*));
    *returnColumnSizes = (int*)malloc(count * sizeof(int));
    *returnSize = count;

    int index = 0;
    for (int i = 0; i < arrSize - 1; i++) {
        if (arr[i + 1] - arr[i] == minDiff) {
            result[index] = (int*)malloc(2 * sizeof(int));
            result[index][0] = arr[i];
            result[index][1] = arr[i + 1];
            (*returnColumnSizes)[index] = 2;
            index++;
        }
    }

    return result;
}