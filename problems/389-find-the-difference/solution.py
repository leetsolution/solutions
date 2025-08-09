class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        s_count = {}
        t_count = {}
        for char in s:
            s_count[char] = s_count.get(char, 0) + 1
        for char in t:
            t_count[char] = t_count.get(char, 0) + 1
        for char in t_count:
            if char not in s_count or t_count[char] != s_count[char]:
                return char