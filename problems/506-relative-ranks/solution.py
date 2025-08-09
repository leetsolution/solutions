class Solution:
    def findRelativeRanks(self, score: List[int]) -> List[str]:
        n = len(score)
        ranks = sorted(range(n), key=lambda i: score[i], reverse=True)
        ans = [""] * n
        ans[ranks[0]] = "Gold Medal"
        if n > 1:
            ans[ranks[1]] = "Silver Medal"
        if n > 2:
            ans[ranks[2]] = "Bronze Medal"
        for i in range(3, n):
            ans[ranks[i]] = str(i + 1)
        return ans