class Solution:
    def smallestPalindrome(self, s: str) -> str:
        counts = {}
        for char in s:
            counts[char] = counts.get(char, 0) + 1
        
        mid_char = ''
        for char, count in counts.items():
            if count % 2 != 0:
                mid_char = char
                counts[char] -= 1
                break
        
        left = ''
        chars = sorted(counts.keys())
        for char in chars:
            left += char * (counts[char] // 2)
        
        return left + mid_char + left[::-1]