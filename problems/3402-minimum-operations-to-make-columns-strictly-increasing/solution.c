int minimumOperations(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    int n = gridColSize[0];
    int operations = 0;

    for (int j = 0; j < n; j++) {
        for (int i = 1; i < m; i++) {
            if (grid[i][j] <= grid[i - 1][j]) {
                int diff = grid[i - 1][j] - grid[i][j] + 1;
                operations += diff;
                grid[i][j] += diff;
            }
        }
    }

    return operations;
}