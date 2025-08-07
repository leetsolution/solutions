class Solution {
public:
    bool canMakeSquare(vector<vector<char>>& grid) {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                char original = grid[i][j];
                grid[i][j] = (original == 'B' ? 'W' : 'B');
                for (int r = 0; r < 2; ++r) {
                    for (int c = 0; c < 2; ++c) {
                        if (grid[r][c] == grid[r + 1][c] &&
                            grid[r][c] == grid[r][c + 1] &&
                            grid[r][c] == grid[r + 1][c + 1]) {
                            return true;
                        }
                    }
                }
                grid[i][j] = original;
            }
        }

        for (int r = 0; r < 2; ++r) {
            for (int c = 0; c < 2; ++c) {
                if (grid[r][c] == grid[r + 1][c] &&
                    grid[r][c] == grid[r][c + 1] &&
                    grid[r][c] == grid[r + 1][c + 1]) {
                    return true;
                }
            }
        }

        return false;
    }
};