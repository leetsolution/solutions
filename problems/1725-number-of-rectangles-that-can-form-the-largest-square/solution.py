class Solution:
    def countGoodRectangles(self, rectangles: List[List[int]]) -> int:
        maxLen = 0
        count = 0
        for l, w in rectangles:
            k = min(l, w)
            if k > maxLen:
                maxLen = k
                count = 1
            elif k == maxLen:
                count += 1
        return count