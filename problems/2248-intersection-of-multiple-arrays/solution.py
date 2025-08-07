class Solution:
    def intersection(self, nums: List[List[int]]) -> List[int]:
        counts = {}
        for lst in nums:
            for num in lst:
                counts[num] = counts.get(num, 0) + 1
        result = []
        for num, count in counts.items():
            if count == len(nums):
                result.append(num)
        result.sort()
        return result