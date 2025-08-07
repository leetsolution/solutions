class Solution:
    def smallestNumber(self, n: int, t: int) -> int:
        while True:
            product = 1
            temp = n
            while temp > 0:
                digit = temp % 10
                product *= digit
                temp //= 10
            
            if t == 1 or (product % t == 0 and t > 0) or (t == 0 and product == 0):
                return n
            
            n += 1