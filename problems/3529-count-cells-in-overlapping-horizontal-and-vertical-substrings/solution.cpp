class Solution {
public:
    int countCells(vector<vector<char>>& grid, string pattern) {
        int m = grid.size();
        int n = grid[0].size();
        int patternLength = pattern.length();

        vector<pair<int, int>> horizontalCells;
        vector<pair<int, int>> verticalCells;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                bool match = true;
                for (int k = 0; k < patternLength; ++k) {
                    int row = i + (j + k) / n;
                    int col = (j + k) % n;
                    if (row >= m || grid[row][col] != pattern[k]) {
                        match = false;
                        break;
                    }
                }
                if (match) {
                    for (int k = 0; k < patternLength; ++k) {
                        int row = i + (j + k) / n;
                        int col = (j + k) % n;
                        horizontalCells.push_back({row, col});
                    }
                }
            }
        }

        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < m; ++i) {
                bool match = true;
                for (int k = 0; k < patternLength; ++k) {
                    int col = j + (i + k) / m;
                    int row = (i + k) % m;
                    if (col >= n || grid[row][col] != pattern[k]) {
                        match = false;
                        break;
                    }
                }
                if (match) {
                    for (int k = 0; k < patternLength; ++k) {
                        int col = j + (i + k) / m;
                        int row = (i + k) % m;
                        verticalCells.push_back({row, col});
                    }
                }
            }
        }

        int count = 0;
        vector<vector<bool>> counted(m, vector<bool>(n, false));
        for (auto& hCell : horizontalCells) {
            for (auto& vCell : verticalCells) {
                if (hCell == vCell && !counted[hCell.first][hCell.second]) {
                    count++;
                    counted[hCell.first][hCell.second] = true;
                }
            }
        }

        return count;
    }
};