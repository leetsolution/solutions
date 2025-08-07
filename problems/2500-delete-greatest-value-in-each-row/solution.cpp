class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; ++i) {
            sort(grid[i].begin(), grid[i].end());
        }

        for (int j = 0; j < n; ++j) {
            int max_val = 0;
            for (int i = 0; i < m; ++i) {
                max_val = max(max_val, grid[i][j]);
            }
            ans += max_val;
        }

        return ans;
    }
};