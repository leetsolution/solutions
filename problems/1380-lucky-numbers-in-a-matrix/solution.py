class Solution:
    def luckyNumbers(self, matrix: List[List[int]]) -> List[int]:
        row_min = []
        col_max = []
        for row in matrix:
            row_min.append(min(row))
        for j in range(len(matrix[0])):
            col_max.append(max(matrix[i][j] for i in range(len(matrix))))
        result = []
        for num in row_min:
            if num in col_max:
                result.append(num)
        return result