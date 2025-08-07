class Solution:
    def countAsterisks(self, s: str) -> int:
        count = 0
        bars = 0
        for char in s:
            if char == '|':
                bars += 1
            elif char == '*' and bars % 2 == 0:
                count += 1
        return count