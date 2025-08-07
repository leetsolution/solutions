class Solution:
    def areSimilar(self, mat: List[List[int]], k: int) -> bool:
        m = len(mat)
        n = len(mat[0])
        original_mat = [row[:] for row in mat]
        for _ in range(k):
            new_mat = [row[:] for row in mat]
            for i in range(m):
                if i % 2 == 0:
                    new_mat[i] = [new_mat[i][-1]] + new_mat[i][:-1]
                else:
                    new_mat[i] = new_mat[i][1:] + [new_mat[i][0]]
            mat = new_mat
        return mat == original_mat