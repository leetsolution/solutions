class Solution:
    def replaceDigits(self, s: str) -> str:
        result = ""
        for i in range(len(s)):
            if i % 2 == 0:
                result += s[i]
            else:
                result += chr(ord(s[i-1]) + int(s[i]))
        return result