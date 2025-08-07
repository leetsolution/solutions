class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> ans(n, 0);
        for (int j = 0; j < n; j++) {
            int maxLen = 0;
            for (int i = 0; i < m; i++) {
                int num = grid[i][j];
                int len = 0;
                if (num == 0) len = 1;
                else if (num < 0) len = to_string(num).length();
                else len = to_string(num).length();
                
                if (num < 0) len++;
                maxLen = max(maxLen, len);
            }
            ans[j] = maxLen;
        }
        return ans;
    }
};