class Solution:
    def zigzagTraversal(self, grid: List[List[int]]) -> List[int]:
        m = len(grid)
        n = len(grid[0])
        result = []
        row = 0
        left_to_right = True
        while row < m:
            if left_to_right:
                for col in range(0, n, 2):
                    result.append(grid[row][col])
            else:
                for col in range(n - 1, -1, -2):
                    result.append(grid[row][col])
            row += 1
            left_to_right = not left_to_right
        return result