class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int n = weight.size();
        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i - 1];
            for (int j = 1; j <= i; ++j) {
                int max_weight = 0;
                for (int k = i - j; k < i; ++k) {
                    max_weight = max(max_weight, weight[k]);
                }
                if (weight[i - 1] < max_weight) {
                    dp[i] = max(dp[i], dp[i - j] + 1);
                }
            }
        }
        return dp[n];
    }
};