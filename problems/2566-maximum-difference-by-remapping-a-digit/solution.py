class Solution:
    def minMaxDifference(self, num: int) -> int:
        s = str(num)
        
        max_val = 0
        for i in range(len(s)):
            digit = s[i]
            temp = s.replace(digit, '9')
            max_val = int(temp)
            break
        
        min_val = 0
        for i in range(len(s)):
            digit = s[i]
            temp = s.replace(digit, '0')
            min_val = int(temp)
            break
            
        return max_val - min_val