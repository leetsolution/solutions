class Solution:
    def numberOfAlternatingGroups(self, colors: List[int]) -> int:
        n = len(colors)
        count = 0
        for i in range(n):
            prev = colors[(i - 1 + n) % n]
            curr = colors[i]
            next_tile = colors[(i + 1) % n]
            if prev != curr and curr != next_tile:
                count += 1
        return count