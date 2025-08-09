class Solution:
    def toHex(self, num: int) -> str:
        if num == 0:
            return "0"
        
        hex_map = "0123456789abcdef"
        result = ""
        
        if num < 0:
            num += 2**32
        
        while num > 0:
            digit = num % 16
            result = hex_map[digit] + result
            num //= 16
            
        return result