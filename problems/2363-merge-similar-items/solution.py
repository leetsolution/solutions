class Solution:
    def mergeSimilarItems(self, items1: List[List[int]], items2: List[List[int]]) -> List[List[int]]:
        d = {}
        for v, w in items1:
            d[v] = d.get(v, 0) + w
        for v, w in items2:
            d[v] = d.get(v, 0) + w
        
        res = []
        for v, w in d.items():
            res.append([v, w])
        
        res.sort()
        return res