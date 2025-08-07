class Solution:
    def buddyStrings(self, s: str, goal: str) -> bool:
        if len(s) != len(goal):
            return False
        if s == goal:
            seen = set()
            for char in s:
                if char in seen:
                    return True
                seen.add(char)
            return False
        diff = []
        for i in range(len(s)):
            if s[i] != goal[i]:
                diff.append(i)
        if len(diff) == 2:
            i, j = diff
            return s[i] == goal[j] and s[j] == goal[i]
        return False