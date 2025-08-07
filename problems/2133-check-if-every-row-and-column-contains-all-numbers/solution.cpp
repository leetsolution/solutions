class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for (int i = 0; i < n; ++i) {
            vector<bool> row_seen(n + 1, false);
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] < 1 || matrix[i][j] > n || row_seen[matrix[i][j]]) {
                    return false;
                }
                row_seen[matrix[i][j]] = true;
            }
            for (int k = 1; k <= n; ++k) {
                if (!row_seen[k]) {
                    return false;
                }
            }
        }

        for (int j = 0; j < n; ++j) {
            vector<bool> col_seen(n + 1, false);
            for (int i = 0; i < n; ++i) {
                if (matrix[i][j] < 1 || matrix[i][j] > n || col_seen[matrix[i][j]]) {
                    return false;
                }
                col_seen[matrix[i][j]] = true;
            }
            for (int k = 1; k <= n; ++k) {
                if (!col_seen[k]) {
                    return false;
                }
            }
        }

        return true;
    }
};