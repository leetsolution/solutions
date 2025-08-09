/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** matrixReshape(int** mat, int matSize, int* matColSize, int r, int c, int* returnSize, int** returnColumnSizes) {
    int m = matSize;
    int n = matColSize[0];
    if (m * n != r * c) {
        *returnSize = m;
        *returnColumnSizes = matColSize;
        return mat;
    }
    int** reshapedMat = (int**)malloc(r * sizeof(int*));
    *returnColumnSizes = (int*)malloc(r * sizeof(int));
    for (int i = 0; i < r; i++) {
        reshapedMat[i] = (int*)malloc(c * sizeof(int));
        (*returnColumnSizes)[i] = c;
    }
    int k = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            reshapedMat[k / c][k % c] = mat[i][j];
            k++;
        }
    }
    *returnSize = r;
    return reshapedMat;
}