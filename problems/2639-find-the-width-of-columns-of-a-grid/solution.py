class Solution:
    def findColumnWidth(self, grid: List[List[int]]) -> List[int]:
        m = len(grid)
        n = len(grid[0])
        ans = [0] * n
        for j in range(n):
            max_width = 0
            for i in range(m):
                num = grid[i][j]
                width = len(str(num))
                if num < 0:
                    width += 1
                max_width = max(max_width, width)
            ans[j] = max_width
        return ans