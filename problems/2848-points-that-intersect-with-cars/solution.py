class Solution:
    def numberOfPoints(self, nums: List[List[int]]) -> int:
        s = set()
        for start, end in nums:
            for i in range(start, end + 1):
                s.add(i)
        return len(s)