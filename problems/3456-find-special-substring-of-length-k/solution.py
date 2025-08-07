class Solution:
    def hasSpecialSubstring(self, s: str, k: int) -> bool:
        n = len(s)
        for i in range(n - k + 1):
            substring = s[i:i + k]
            if len(set(substring)) == 1:
                if i > 0 and s[i - 1] == substring[0]:
                    continue
                if i + k < n and s[i + k] == substring[0]:
                    continue
                return True
        return False