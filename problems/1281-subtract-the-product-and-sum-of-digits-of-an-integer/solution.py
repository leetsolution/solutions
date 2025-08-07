class Solution:
    def subtractProductAndSum(self, n: int) -> int:
        product = 1
        sum_digits = 0
        for digit in str(n):
            digit = int(digit)
            product *= digit
            sum_digits += digit
        return product - sum_digits