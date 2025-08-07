/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* rowAndMaximumOnes(int** mat, int matSize, int* matColSize, int* returnSize) {
    int max_ones = -1;
    int row_index = -1;
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;

    for (int i = 0; i < matSize; i++) {
        int ones_count = 0;
        for (int j = 0; j < matColSize[i]; j++) {
            if (mat[i][j] == 1) {
                ones_count++;
            }
        }

        if (ones_count > max_ones) {
            max_ones = ones_count;
            row_index = i;
        }
    }

    result[0] = row_index;
    result[1] = max_ones;

    return result;
}