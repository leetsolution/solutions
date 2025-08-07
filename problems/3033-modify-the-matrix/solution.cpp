class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        for (int j = 0; j < n; ++j) {
            int max_val = -1;
            for (int i = 0; i < m; ++i) {
                max_val = max(max_val, matrix[i][j]);
            }

            for (int i = 0; i < m; ++i) {
                if (matrix[i][j] == -1) {
                    matrix[i][j] = max_val;
                }
            }
        }

        return matrix;
    }
};