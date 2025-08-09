class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        words = s.split()
        if len(pattern) != len(words):
            return False
        p_map = {}
        w_map = {}
        for i in range(len(pattern)):
            p = pattern[i]
            w = words[i]
            if p not in p_map:
                if w in w_map:
                    return False
                p_map[p] = w
                w_map[w] = p
            elif p_map[p] != w:
                return False
        return True