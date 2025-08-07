class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        for (int k = 0; k < 4; ++k) {
            if (mat == target) {
                return true;
            }
            vector<vector<int>> rotated(n, vector<int>(n));
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    rotated[j][n - 1 - i] = mat[i][j];
                }
            }
            mat = rotated;
        }
        return false;
    }
};