class Solution:
    def sumBase(self, n: int, k: int) -> int:
        sum_digits = 0
        while n > 0:
            digit = n % k
            sum_digits += digit
            n //= k
        return sum_digits