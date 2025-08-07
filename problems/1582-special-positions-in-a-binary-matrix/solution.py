class Solution:
    def numSpecial(self, mat: List[List[int]]) -> int:
        m = len(mat)
        n = len(mat[0])
        count = 0
        row_sums = [sum(row) for row in mat]
        col_sums = [sum(mat[i][j] for i in range(m)) for j in range(n)]
        for i in range(m):
            for j in range(n):
                if mat[i][j] == 1 and row_sums[i] == 1 and col_sums[j] == 1:
                    count += 1
        return count