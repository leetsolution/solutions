/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

typedef struct {
    int val;
    int index;
} Pair;

int compare(const void *a, const void *b) {
    return ((Pair*)a)->val - ((Pair*)b)->val;
}

int* arrayRankTransform(int* arr, int arrSize, int* returnSize) {
    *returnSize = arrSize;
    int* result = (int*)malloc(arrSize * sizeof(int));
    if (arrSize == 0) {
        return result;
    }

    Pair* pairs = (Pair*)malloc(arrSize * sizeof(Pair));
    for (int i = 0; i < arrSize; i++) {
        pairs[i].val = arr[i];
        pairs[i].index = i;
    }

    qsort(pairs, arrSize, sizeof(Pair), compare);

    int rank = 1;
    result[pairs[0].index] = rank;
    for (int i = 1; i < arrSize; i++) {
        if (pairs[i].val != pairs[i - 1].val) {
            rank++;
        }
        result[pairs[i].index] = rank;
    }

    free(pairs);
    return result;
}