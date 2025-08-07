from typing import List

class Solution:
    def maxCollectedFruits(self, fruits: List[List[int]]) -> int:
        n = len(fruits)
        main_diagonal = sum(fruits[i][i] for i in range(n))
        top_right = self.compute_top_right(fruits)
        bottom_left = self.compute_bottom_left(fruits)
        # Subtract bottom-right corner twice
        return main_diagonal + top_right + bottom_left - 2 * fruits[n - 1][n - 1]

    def compute_top_right(self, fruits: List[List[int]]) -> int:
        n = len(fruits)
        dp = [[0] * n for _ in range(n)]
        dp[0][n - 1] = fruits[0][n - 1]
        for x in range(n):
            for y in range(n):
                if x >= y and not (x == n - 1 and y == n - 1):
                    continue
                for dx, dy in [(1, -1), (1, 0), (1, 1)]:
                    i, j = x - dx, y - dy
                    if i < 0 or i >= n or j < 0 or j >= n:
                        continue
                    if i < j and j < n - 1 - i:
                        continue
                    dp[x][y] = max(dp[x][y], dp[i][j] + fruits[x][y])
        return dp[n - 1][n - 1]

    def compute_bottom_left(self, fruits: List[List[int]]) -> int:
        n = len(fruits)
        dp = [[0] * n for _ in range(n)]
        dp[n - 1][0] = fruits[n - 1][0]
        for y in range(n):
            for x in range(n):
                if x <= y and not (x == n - 1 and y == n - 1):
                    continue
                for dx, dy in [(-1, 1), (0, 1), (1, 1)]:
                    i, j = x - dx, y - dy
                    if i < 0 or i >= n or j < 0 or j >= n:
                        continue
                    if j < i and i < n - 1 - j:
                        continue
                    dp[x][y] = max(dp[x][y], dp[i][j] + fruits[x][y])
        return dp[n - 1][n - 1]
