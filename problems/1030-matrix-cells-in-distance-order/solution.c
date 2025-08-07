/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

int dist(int r1, int c1, int r2, int c2) {
    return abs(r1 - r2) + abs(c1 - c2);
}

int** allCellsDistOrder(int rows, int cols, int rCenter, int cCenter, int* returnSize, int** returnColumnSizes) {
    *returnSize = rows * cols;
    *returnColumnSizes = (int*)malloc(sizeof(int) * (*returnSize));
    int** result = (int**)malloc(sizeof(int*) * (*returnSize));

    for (int i = 0; i < *returnSize; i++) {
        result[i] = (int*)malloc(sizeof(int) * 2);
        (*returnColumnSizes)[i] = 2;
    }

    int index = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[index][0] = i;
            result[index][1] = j;
            index++;
        }
    }

    for (int i = 0; i < *returnSize - 1; i++) {
        for (int j = 0; j < *returnSize - i - 1; j++) {
            if (dist(result[j][0], result[j][1], rCenter, cCenter) > dist(result[j + 1][0], result[j + 1][1], rCenter, cCenter)) {
                int temp_r = result[j][0];
                int temp_c = result[j][1];
                result[j][0] = result[j + 1][0];
                result[j][1] = result[j + 1][1];
                result[j + 1][0] = temp_r;
                result[j + 1][1] = temp_c;
            }
        }
    }

    return result;
}