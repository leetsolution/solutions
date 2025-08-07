class Solution:
    def numberOfSpecialChars(self, word: str) -> int:
        lower = set()
        upper = set()
        for char in word:
            if 'a' <= char <= 'z':
                lower.add(char)
            else:
                upper.add(char.lower())
        return len(lower.intersection(upper))