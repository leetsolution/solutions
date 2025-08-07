from typing import List

class Solution:
    def findCoins(self, numWays: List[int]) -> List[int]:
        n = len(numWays)
        dp = [0] * (n + 1)
        dp[0] = 1
        coins = []

        for i in range(n):
            amount = i + 1
            expected = numWays[i]

            if expected > 0 and dp[amount] == expected - 1:
                coins.append(amount)
                for j in range(amount, n + 1):
                    dp[j] += dp[j - amount]

            if dp[amount] != expected:
                return []

        return coins
