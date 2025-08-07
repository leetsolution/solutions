class Solution:
    def maxLengthBetweenEqualCharacters(self, s: str) -> int:
        max_length = -1
        for i in range(len(s)):
            for j in range(len(s) - 1, i, -1):
                if s[i] == s[j]:
                    max_length = max(max_length, j - i - 1)
                    break
        return max_length