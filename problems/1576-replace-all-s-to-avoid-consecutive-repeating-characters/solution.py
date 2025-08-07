class Solution:
    def modifyString(self, s: str) -> str:
        s = list(s)
        n = len(s)
        for i in range(n):
            if s[i] == '?':
                for char_code in range(ord('a'), ord('z') + 1):
                    char = chr(char_code)
                    if (i > 0 and s[i - 1] == char) or (i < n - 1 and s[i + 1] != '?' and s[i + 1] == char):
                        continue
                    else:
                        s[i] = char
                        break
        return ''.join(s)