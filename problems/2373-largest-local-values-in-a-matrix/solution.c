/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** largestLocal(int** grid, int gridSize, int* gridColSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = gridSize - 2;
    *returnColumnSizes = (int*)malloc(sizeof(int) * (*returnSize));
    int** result = (int**)malloc(sizeof(int*) * (*returnSize));
    for (int i = 0; i < *returnSize; i++) {
        result[i] = (int*)malloc(sizeof(int) * (*returnSize));
        (*returnColumnSizes)[i] = *returnSize;
    }

    for (int i = 0; i < gridSize - 2; i++) {
        for (int j = 0; j < gridSize - 2; j++) {
            int maxVal = 0;
            for (int x = i; x < i + 3; x++) {
                for (int y = j; y < j + 3; y++) {
                    if (grid[x][y] > maxVal) {
                        maxVal = grid[x][y];
                    }
                }
            }
            result[i][j] = maxVal;
        }
    }

    return result;
}