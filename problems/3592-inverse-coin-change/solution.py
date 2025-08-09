class Solution:
    def findCoins(self, numWays: List[int]) -> List[int]:
        n = len(numWays)
        coins = []
        
        def calculate_ways(target, denominations):
            dp = [0] * (target + 1)
            dp[0] = 1
            
            for coin in denominations:
                for i in range(coin, target + 1):
                    dp[i] += dp[i - coin]
            
            return dp[target]

        
        for coin in range(1, n + 1):
            if numWays[coin-1] > 0:
                temp_coins = coins + [coin]
                possible = True
                for i in range(1, n+1):
                    calculated_ways = calculate_ways(i, temp_coins)
                    if numWays[i-1] != calculated_ways:
                        possible = False
                        break
                if possible:
                    coins.append(coin)
        
        temp_coins = coins
        possible = True
        for i in range(1, n+1):
            calculated_ways = calculate_ways(i, temp_coins)
            if numWays[i-1] != calculated_ways:
                possible = False
                break
        
        if not possible:
            return []

        if len(coins) == 0 and numWays[0] != 1:
           return []

        if len(coins) == 0 and numWays[0] == 1:
            return []
            
        return sorted(coins)