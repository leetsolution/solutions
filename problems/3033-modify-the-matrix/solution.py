class Solution:
    def modifiedMatrix(self, matrix: List[List[int]]) -> List[List[int]]:
        m = len(matrix)
        n = len(matrix[0])
        answer = [row[:] for row in matrix]
        for j in range(n):
            max_val = -1
            for i in range(m):
                max_val = max(max_val, matrix[i][j])
            for i in range(m):
                if matrix[i][j] == -1:
                    answer[i][j] = max_val
        return answer