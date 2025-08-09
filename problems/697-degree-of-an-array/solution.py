class Solution:
    def findShortestSubArray(self, nums: List[int]) -> int:
        count = {}
        first = {}
        last = {}
        for i, num in enumerate(nums):
            if num not in count:
                count[num] = 0
                first[num] = i
            count[num] += 1
            last[num] = i
        max_count = max(count.values())
        min_length = float('inf')
        for num, c in count.items():
            if c == max_count:
                min_length = min(min_length, last[num] - first[num] + 1)
        return min_length