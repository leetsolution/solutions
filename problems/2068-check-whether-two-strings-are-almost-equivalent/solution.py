class Solution:
    def checkAlmostEquivalent(self, word1: str, word2: str) -> bool:
        freq = {}
        for char in word1:
            freq[char] = freq.get(char, 0) + 1
        for char in word2:
            freq[char] = freq.get(char, 0) - 1
        for count in freq.values():
            if abs(count) > 3:
                return False
        return True