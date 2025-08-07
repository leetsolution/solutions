class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        soldiers = []
        for i, row in enumerate(mat):
            soldiers.append((sum(row), i))
        
        soldiers.sort()
        
        result = []
        for i in range(k):
            result.append(soldiers[i][1])
        
        return result