class Solution:
    def checkDivisibility(self, n: int) -> bool:
        num_str = str(n)
        digit_sum = 0
        digit_product = 1
        for digit in num_str:
            digit = int(digit)
            digit_sum += digit
            digit_product *= digit
        
        total = digit_sum + digit_product
        
        return n % total == 0