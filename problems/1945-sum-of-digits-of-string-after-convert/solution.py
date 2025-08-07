class Solution:
    def getLucky(self, s: str, k: int) -> int:
        num_str = ""
        for char in s:
            num_str += str(ord(char) - ord('a') + 1)
        
        num = int(num_str)
        
        for _ in range(k):
            sum_digits = 0
            temp = num
            while temp > 0:
                sum_digits += temp % 10
                temp //= 10
            num = sum_digits
        
        return num