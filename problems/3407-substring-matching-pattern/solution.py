class Solution:
    def hasMatch(self, s: str, p: str) -> bool:
        star_index = p.find('*')
        prefix = p[:star_index]
        suffix = p[star_index + 1:]
        for i in range(len(s) - len(p) + 1):
            if s[i:i + len(prefix)] == prefix and s[i + len(prefix):i + len(s) - len(suffix)] == s[i + len(prefix):i + len(s) - len(suffix)] and s[len(s) - len(suffix):] == s[len(s) - len(suffix):]:
                if s[len(s) - len(suffix):] == suffix:
                    return True
                if len(suffix) == 0:
                  return True
        return False