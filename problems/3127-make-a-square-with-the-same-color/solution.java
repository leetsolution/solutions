class Solution {
    public boolean canMakeSquare(char[][] grid) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                if (grid[i][j] == grid[i + 1][j] && grid[i][j] == grid[i][j + 1] && grid[i][j] == grid[i + 1][j + 1]) {
                    return true;
                }
            }
        }

        for (int r = 0; r < 3; r++) {
            for (int c = 0; c < 3; c++) {
                char original = grid[r][c];
                char target = (original == 'B') ? 'W' : 'B';
                grid[r][c] = target;

                for (int i = 0; i < 2; i++) {
                    for (int j = 0; j < 2; j++) {
                        if (grid[i][j] == grid[i + 1][j] && grid[i][j] == grid[i][j + 1] && grid[i][j] == grid[i + 1][j + 1]) {
                            grid[r][c] = original;
                            return true;
                        }
                    }
                }
                grid[r][c] = original;
            }
        }

        return false;
    }
}