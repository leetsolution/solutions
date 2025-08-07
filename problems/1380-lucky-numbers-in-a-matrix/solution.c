/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* luckyNumbers(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int m = matrixSize;
    int n = matrixColSize[0];
    int* lucky = (int*)malloc(m * n * sizeof(int));
    *returnSize = 0;

    for (int i = 0; i < m; i++) {
        int min_row = matrix[i][0];
        int col_index = 0;
        for (int j = 1; j < n; j++) {
            if (matrix[i][j] < min_row) {
                min_row = matrix[i][j];
                col_index = j;
            }
        }

        int max_col = matrix[0][col_index];
        int is_lucky = 1;
        for (int k = 1; k < m; k++) {
            if (matrix[k][col_index] > max_col) {
                max_col = matrix[k][col_index];
                is_lucky = 0;
                break;
            }
        }

        if (is_lucky) {
            lucky[*returnSize] = min_row;
            (*returnSize)++;
        }
    }

    return lucky;
}