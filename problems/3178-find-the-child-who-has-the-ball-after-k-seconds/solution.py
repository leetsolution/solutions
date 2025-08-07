class Solution:
    def numberOfChild(self, n: int, k: int) -> int:
        period = (n - 1) * 2
        rem = k % period
        if rem < n:
            return rem
        else:
            return n - 1 - (rem - (n - 1))