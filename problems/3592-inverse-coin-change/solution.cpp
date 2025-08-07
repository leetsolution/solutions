class Solution {
public:
    vector<int> findCoins(vector<int>& numWays) {
        int n = numWays.size();
        vector<int> dp(n + 1, 0);
        vector<int> coins;
        dp[0] = 1;

        for (int i = 0; i < n; ++i) {
            int amount = i + 1;
            int expected = numWays[i];

            if (expected > 0 && dp[amount] == expected - 1) {
                coins.push_back(amount);
                for (int j = amount; j <= n; ++j) {
                    dp[j] += dp[j - amount];
                }
            }

            if (dp[amount] != expected) {
                return {};
            }
        }

        return coins;
    }
};
