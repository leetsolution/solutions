class Solution:
    def checkValid(self, matrix: List[List[int]]) -> bool:
        n = len(matrix)
        for i in range(n):
            row_set = set()
            col_set = set()
            for j in range(n):
                row_set.add(matrix[i][j])
                col_set.add(matrix[j][i])
            if len(row_set) != n or len(col_set) != n:
                return False
            for k in range(1, n + 1):
                if k not in row_set or k not in col_set:
                    return False
        return True