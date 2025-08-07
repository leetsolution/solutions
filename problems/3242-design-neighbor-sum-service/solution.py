class NeighborSum:

    def __init__(self, grid: List[List[int]]):
        self.grid = grid
        self.n = len(grid)
        self.pos = {}
        for i in range(self.n):
            for j in range(self.n):
                self.pos[grid[i][j]] = (i, j)

    def adjacentSum(self, value: int) -> int:
        x, y = self.pos[value]
        ans = 0
        if x > 0:
            ans += self.grid[x - 1][y]
        if x < self.n - 1:
            ans += self.grid[x + 1][y]
        if y > 0:
            ans += self.grid[x][y - 1]
        if y < self.n - 1:
            ans += self.grid[x][y + 1]
        return ans

    def diagonalSum(self, value: int) -> int:
        x, y = self.pos[value]
        ans = 0
        if x > 0 and y > 0:
            ans += self.grid[x - 1][y - 1]
        if x > 0 and y < self.n - 1:
            ans += self.grid[x - 1][y + 1]
        if x < self.n - 1 and y > 0:
            ans += self.grid[x + 1][y - 1]
        if x < self.n - 1 and y < self.n - 1:
            ans += self.grid[x + 1][y + 1]
        return ans