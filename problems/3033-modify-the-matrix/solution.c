/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** modifiedMatrix(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = matrixSize;
    *returnColumnSizes = (int*)malloc(matrixSize * sizeof(int));
    for (int i = 0; i < matrixSize; i++) {
        (*returnColumnSizes)[i] = matrixColSize[0];
    }

    int** answer = (int**)malloc(matrixSize * sizeof(int*));
    for (int i = 0; i < matrixSize; i++) {
        answer[i] = (int*)malloc(matrixColSize[0] * sizeof(int));
        for (int j = 0; j < matrixColSize[0]; j++) {
            answer[i][j] = matrix[i][j];
        }
    }

    for (int j = 0; j < matrixColSize[0]; j++) {
        int maxVal = -1;
        for (int i = 0; i < matrixSize; i++) {
            if (matrix[i][j] > maxVal) {
                maxVal = matrix[i][j];
            }
        }

        for (int i = 0; i < matrixSize; i++) {
            if (answer[i][j] == -1) {
                answer[i][j] = maxVal;
            }
        }
    }

    return answer;
}