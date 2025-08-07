class Solution:
    def longestNiceSubstring(self, s: str) -> str:
        if not s:
            return ""
        chars = set(s)
        for i, char in enumerate(s):
            if char.swapcase() not in chars:
                s1 = self.longestNiceSubstring(s[:i])
                s2 = self.longestNiceSubstring(s[i + 1:])
                return s1 if len(s1) >= len(s2) else s2
        return s