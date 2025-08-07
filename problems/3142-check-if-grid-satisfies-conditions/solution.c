bool satisfiesConditions(int** grid, int gridSize, int* gridColSize) {
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[0]; j++) {
            if (i + 1 < gridSize && grid[i][j] != grid[i + 1][j]) {
                return false;
            }
            if (j + 1 < gridColSize[0] && grid[i][j] == grid[i][j + 1]) {
                return false;
            }
        }
    }
    return true;
}