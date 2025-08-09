class Solution:
    def licenseKeyFormatting(self, s: str, k: int) -> str:
        s = s.replace("-", "").upper()
        n = len(s)
        if n == 0:
            return ""
        first_group_len = n % k
        res = ""
        if first_group_len > 0:
            res += s[:first_group_len]
            if n > k:
                res += "-"
        for i in range(first_group_len, n, k):
            res += s[i:i+k]
            if i + k < n:
                res += "-"
        return res