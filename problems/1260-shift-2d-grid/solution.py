class Solution:
    def shiftGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        m = len(grid)
        n = len(grid[0])
        k = k % (m * n)
        
        new_grid = [[0] * n for _ in range(m)]
        
        for i in range(m):
            for j in range(n):
                new_j = (j + k) % n
                new_i = (i + (j + k) // n) % m
                new_grid[new_i][new_j] = grid[i][j]
                
        return new_grid