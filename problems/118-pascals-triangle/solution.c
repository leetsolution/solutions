/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    int **triangle = (int**)malloc(numRows * sizeof(int*));
    *returnColumnSizes = (int*)malloc(numRows * sizeof(int));
    *returnSize = numRows;

    for (int i = 0; i < numRows; i++) {
        (*returnColumnSizes)[i] = i + 1;
        triangle[i] = (int*)malloc((i + 1) * sizeof(int));

        triangle[i][0] = 1;
        triangle[i][i] = 1;

        for (int j = 1; j < i; j++) {
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
    }

    return triangle;
}