class Solution:
    def minCuttingCost(self, n: int, m: int, k: int) -> int:
        if n <= k and m <= k:
            return 0
        
        if n > k and m > k:
            return min(n % k * (n - n % k) if n % k != 0 else (n - k) * k, (n // k) * k * (n - (n // k) * k)) + min(m % k * (m - m % k) if m % k != 0 else (m - k) * k, (m // k) * k * (m - (m // k) * k))
        
        if n > k:
            if n <= 2 * k:
                return min(n % k * (n - n % k) if n % k != 0 else (n - k) * k, (n // k) * k * (n - (n // k) * k))
            else:
                
                
                cost1 = (n // k) * k * (n % k)
                rem = n % k
                cost2 = rem * (n - rem)
                
                return min(cost1, cost2)
        else:
            if m <= 2 * k:
                return min(m % k * (m - m % k) if m % k != 0 else (m - k) * k, (m // k) * k * (m - (m // k) * k))
            else:
                
                cost1 = (m // k) * k * (m % k)
                rem = m % k
                cost2 = rem * (m - rem)
                
                return min(cost1, cost2)