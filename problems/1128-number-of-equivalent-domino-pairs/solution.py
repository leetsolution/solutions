class Solution:
    def numEquivDominoPairs(self, dominoes: List[List[int]]) -> int:
        count = {}
        ans = 0
        for domino in dominoes:
            domino.sort()
            key = tuple(domino)
            if key in count:
                ans += count[key]
                count[key] += 1
            else:
                count[key] = 1
        return ans