/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** flipAndInvertImage(int** image, int imageSize, int* imageColSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = imageSize;
    *returnColumnSizes = (int*)malloc(sizeof(int) * imageSize);
    int** result = (int**)malloc(sizeof(int*) * imageSize);
    for (int i = 0; i < imageSize; i++) {
        (*returnColumnSizes)[i] = imageColSize[0];
        result[i] = (int*)malloc(sizeof(int) * imageColSize[0]);
        for (int j = 0; j < imageColSize[0]; j++) {
            result[i][j] = 1 - image[i][imageColSize[0] - 1 - j];
        }
    }
    return result;
}