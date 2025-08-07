bool canMakeSquare(char** grid, int gridSize, int* gridColSize) {
    for (int i = 0; i < gridSize - 1; i++) {
        for (int j = 0; j < *gridColSize - 1; j++) {
            if (grid[i][j] == grid[i + 1][j] && grid[i][j] == grid[i][j + 1] && grid[i][j] == grid[i + 1][j + 1]) {
                return true;
            }
        }
    }

    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < *gridColSize; j++) {
            char original = grid[i][j];
            grid[i][j] = (original == 'B') ? 'W' : 'B';

            for (int row = 0; row < gridSize - 1; row++) {
                for (int col = 0; col < *gridColSize - 1; col++) {
                    if (grid[row][col] == grid[row + 1][col] && grid[row][col] == grid[row][col + 1] && grid[row][col] == grid[row + 1][col + 1]) {
                        return true;
                    }
                }
            }
            grid[i][j] = original;
        }
    }

    return false;
}