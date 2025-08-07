class Solution:
    def alternateDigitSum(self, n: int) -> int:
        s = str(n)
        ans = 0
        sign = 1
        for digit in s:
            ans += sign * int(digit)
            sign *= -1
        return ans