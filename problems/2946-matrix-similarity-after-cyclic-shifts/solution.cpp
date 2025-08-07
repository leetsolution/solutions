class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> original_mat = mat;
        for (int i = 0; i < k; ++i) {
            vector<vector<int>> next_mat(m, vector<int>(n));
            for (int j = 0; j < m; ++j) {
                if (j % 2 == 0) {
                    for (int l = 0; l < n; ++l) {
                        next_mat[j][l] = mat[j][(l + 1) % n];
                    }
                } else {
                    for (int l = 0; l < n; ++l) {
                        next_mat[j][l] = mat[j][(l + n - 1) % n];
                    }
                }
            }
            mat = next_mat;
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] != original_mat[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
};