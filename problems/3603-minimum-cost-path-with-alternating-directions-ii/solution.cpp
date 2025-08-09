class Solution {
public:
    long long minCost(int m, int n, vector<vector<int>>& waitCost) {
        vector<vector<long long>> dp(m, vector<long long>(n, LLONG_MAX));
        dp[0][0] = 1;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dp[i][j] == LLONG_MAX) continue;

                if ((i + j) % 2 == 0) {
                    if (i + 1 < m) {
                        dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + (long long)(i + 2) * (j + 1));
                    }
                    if (j + 1 < n) {
                        dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + (long long)(i + 1) * (j + 2));
                    }
                } else {
                    dp[i][j] += waitCost[i][j];
                    if (i + 1 < m) {
                        dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + (long long)(i + 2) * (j + 1));
                    }
                    if (j + 1 < n) {
                        dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + (long long)(i + 1) * (j + 2));
                    }
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};