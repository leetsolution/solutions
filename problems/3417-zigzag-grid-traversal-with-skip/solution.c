/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* zigzagTraversal(int** grid, int gridSize, int* gridColSize, int* returnSize) {
    int m = gridSize;
    int n = gridColSize[0];
    int* result = (int*)malloc(sizeof(int) * ((m * n + 1) / 2));
    *returnSize = 0;
    int row = 0;
    int col = 0;
    int direction = 1; 

    while (row < m) {
        if (direction == 1) {
            int current_col = 0;
            while (current_col < n) {
                result[(*returnSize)++] = grid[row][current_col];
                current_col += 2;
            }
        } else {
            int current_col = n - 1;
            while (current_col >= 0) {
                result[(*returnSize)++] = grid[row][current_col];
                current_col -= 2;
            }
        }
        row++;
        direction *= -1;
    }
    return result;
}