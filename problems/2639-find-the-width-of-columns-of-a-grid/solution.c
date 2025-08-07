/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findColumnWidth(int** grid, int gridSize, int* gridColSize, int* returnSize) {
    int n = *gridColSize;
    int* ans = (int*)malloc(n * sizeof(int));
    *returnSize = n;

    for (int j = 0; j < n; j++) {
        int max_width = 0;
        for (int i = 0; i < gridSize; i++) {
            int num = grid[i][j];
            int width = 0;
            int temp = num;
            if (temp < 0) {
                width++;
                temp = -temp;
            }
            if (temp == 0) {
                width++;
            } else {
                while (temp > 0) {
                    width++;
                    temp /= 10;
                }
            }
            if (width > max_width) {
                max_width = width;
            }
        }
        ans[j] = max_width;
    }

    return ans;
}