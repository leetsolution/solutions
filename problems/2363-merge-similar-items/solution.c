/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** mergeSimilarItems(int** items1, int items1Size, int* items1ColSize, int** items2, int items2Size, int* items2ColSize, int* returnSize, int** returnColumnSizes) {
    int hash[1001] = {0};
    for (int i = 0; i < items1Size; i++) {
        hash[items1[i][0]] += items1[i][1];
    }
    for (int i = 0; i < items2Size; i++) {
        hash[items2[i][0]] += items2[i][1];
    }
    int count = 0;
    for (int i = 1; i <= 1000; i++) {
        if (hash[i] != 0) {
            count++;
        }
    }
    int** result = (int**)malloc(sizeof(int*) * count);
    *returnColumnSizes = (int*)malloc(sizeof(int) * count);
    *returnSize = 0;
    for (int i = 1; i <= 1000; i++) {
        if (hash[i] != 0) {
            result[*returnSize] = (int*)malloc(sizeof(int) * 2);
            result[*returnSize][0] = i;
            result[*returnSize][1] = hash[i];
            (*returnColumnSizes)[*returnSize] = 2;
            (*returnSize)++;
        }
    }

    for (int i = 0; i < *returnSize - 1; i++) {
        for (int j = 0; j < *returnSize - i - 1; j++) {
            if (result[j][0] > result[j + 1][0]) {
                int temp0 = result[j][0];
                int temp1 = result[j][1];
                result[j][0] = result[j + 1][0];
                result[j][1] = result[j + 1][1];
                result[j + 1][0] = temp0;
                result[j + 1][1] = temp1;
            }
        }
    }
    return result;
}