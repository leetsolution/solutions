class Solution:
    def maxProduct(self, n: int) -> int:
        s = str(n)
        max_product = 0
        for i in range(len(s)):
            for j in range(len(s)):
                max_product = max(max_product, int(s[i]) * int(s[j]))
        return max_product