class Solution:
    def minimumOperations(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        ans = 0
        for j in range(n):
            prev = -1
            for i in range(m):
                if grid[i][j] <= prev:
                    ans += (prev - grid[i][j] + 1)
                    grid[i][j] = prev + 1
                prev = grid[i][j]
        return ans