class Solution:
    def reverseOnlyLetters(self, s: str) -> str:
        letters = [c for c in s if c.isalpha()]
        letters.reverse()
        result = ""
        idx = 0
        for c in s:
            if c.isalpha():
                result += letters[idx]
                idx += 1
            else:
                result += c
        return result