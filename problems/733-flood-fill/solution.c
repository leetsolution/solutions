/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int color, int* returnSize, int** returnColumnSizes) {
    int originalColor = image[sr][sc];
    if (originalColor == color) return image;
    int m = imageSize;
    int n = imageColSize[0];
    int** newImage = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        newImage[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            newImage[i][j] = image[i][j];
        }
    }
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    int stack[m * n][2];
    int top = 0;
    stack[top][0] = sr;
    stack[top][1] = sc;
    top++;
    while (top > 0) {
        top--;
        int x = stack[top][0];
        int y = stack[top][1];
        if (x < 0 || x >= m || y < 0 || y >= n || newImage[x][y] != originalColor) continue;
        newImage[x][y] = color;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            stack[top][0] = nx;
            stack[top][1] = ny;
            top++;
        }
    }
    *returnSize = imageSize;
    *returnColumnSizes = imageColSize;
    return newImage;
}