/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** imageSmoother(int** img, int imgSize, int* imgColSize, int* returnSize, int** returnColumnSizes) {
    int m = imgSize;
    int n = imgColSize[0];
    int** smoothedImg = (int**)malloc(m * sizeof(int*));
    *returnColumnSizes = (int*)malloc(m * sizeof(int));
    *returnSize = m;
    for (int i = 0; i < m; i++) {
        smoothedImg[i] = (int*)malloc(n * sizeof(int));
        (*returnColumnSizes)[i] = n;
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int sum = 0;
            int count = 0;
            for (int x = -1; x <= 1; x++) {
                for (int y = -1; y <= 1; y++) {
                    int row = i + x;
                    int col = j + y;
                    if (row >= 0 && row < m && col >= 0 && col < n) {
                        sum += img[row][col];
                        count++;
                    }
                }
            }
            smoothedImg[i][j] = sum / count;
        }
    }
    return smoothedImg;
}