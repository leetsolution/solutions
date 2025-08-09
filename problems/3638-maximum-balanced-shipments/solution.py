class Solution:
    def maxBalancedShipments(self, weight: List[int]) -> int:
        n = len(weight)
        dp = [0] * (n + 1)
        for i in range(1, n + 1):
            dp[i] = dp[i - 1]
            for j in range(1, i + 1):
                sub_array = weight[i - j:i]
                if sub_array[-1] < max(sub_array):
                    dp[i] = max(dp[i], dp[i - j] + 1)
        return dp[n]