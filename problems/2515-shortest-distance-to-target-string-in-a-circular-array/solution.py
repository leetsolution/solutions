class Solution:
    def closestTarget(self, words: List[str], target: str, startIndex: int) -> int:
        n = len(words)
        min_dist = float('inf')
        found = False
        for i in range(n):
            if words[i] == target:
                found = True
                dist1 = abs(i - startIndex)
                dist2 = n - dist1
                min_dist = min(min_dist, min(dist1, dist2))
        if not found:
            return -1
        else:
            return min_dist