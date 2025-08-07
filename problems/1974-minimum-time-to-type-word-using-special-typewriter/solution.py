class Solution:
    def minTimeToType(self, word: str) -> int:
        current = 'a'
        total_time = 0
        for char in word:
            diff = abs(ord(char) - ord(current))
            total_time += min(diff, 26 - diff) + 1
            current = char
        return total_time