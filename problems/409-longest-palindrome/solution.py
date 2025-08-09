class Solution:
    def longestPalindrome(self, s: str) -> int:
        counts = {}
        for char in s:
            counts[char] = counts.get(char, 0) + 1
        
        length = 0
        odd_exists = False
        for count in counts.values():
            if count % 2 == 0:
                length += count
            else:
                length += count - 1
                odd_exists = True
        
        if odd_exists:
            length += 1
        return length