class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        vector<int> result;
        int m = grid.size();
        int n = grid[0].size();
        bool right = true;
        for (int i = 0; i < m; ++i) {
            if (right) {
                for (int j = 0; j < n; j += 2) {
                    result.push_back(grid[i][j]);
                }
            } else {
                for (int j = n - 1; j >= 0; j -= 2) {
                    result.push_back(grid[i][j]);
                }
            }
            right = !right;
        }
        return result;
    }
};