int surfaceArea(int** grid, int gridSize, int* gridColSize) {
    int totalArea = 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            int height = grid[i][j];
            if (height > 0) {
                totalArea += 2; // Top and bottom surfaces
                totalArea += (height > 1) ? 4 * (height -1) : 0;
                if (i > 0) totalArea -= 2 * min(height, grid[i - 1][j]);
                if (i < gridSize - 1) totalArea -= 2 * min(height, grid[i + 1][j]);
                if (j > 0) totalArea -= 2 * min(height, grid[i][j - 1]);
                if (j < gridColSize[i] - 1) totalArea -= 2 * min(height, grid[i][j + 1]);
            }
        }
    }
    return totalArea;
}