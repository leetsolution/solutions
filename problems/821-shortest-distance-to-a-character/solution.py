class Solution:
    def shortestToChar(self, s: str, c: str) -> List[int]:
        indices = [i for i, char in enumerate(s) if char == c]
        result = []
        for i, char in enumerate(s):
            min_dist = float('inf')
            for index in indices:
                min_dist = min(min_dist, abs(i - index))
            result.append(min_dist)
        return result