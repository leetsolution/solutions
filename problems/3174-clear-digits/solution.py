class Solution:
    def clearDigits(self, s: str) -> str:
        s = list(s)
        i = 0
        while i < len(s):
            if s[i].isdigit():
                found = False
                for j in range(i - 1, -1, -1):
                    if not s[j].isdigit():
                        del s[i]
                        del s[j]
                        i = 0
                        found = True
                        break
                if not found:
                    i += 1
            else:
                i += 1
        return "".join(s)