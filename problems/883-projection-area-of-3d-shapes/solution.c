int projectionArea(int** grid, int gridSize, int* gridColSize) {
    int xy_area = 0;
    int yz_area = 0;
    int zx_area = 0;
    for (int i = 0; i < gridSize; i++) {
        int max_row = 0;
        int max_col = 0;
        for (int j = 0; j < gridSize; j++) {
            if (grid[i][j] > 0) {
                xy_area++;
            }
            max_row = max(max_row, grid[i][j]);
            max_col = max(max_col, grid[j][i]);
        }
        yz_area += max_row;
        zx_area += max_col;
    }
    return xy_area + yz_area + zx_area;
}