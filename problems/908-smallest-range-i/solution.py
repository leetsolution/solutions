class Solution:
    def smallestRangeI(self, nums: List[int], k: int) -> int:
        min_num = min(nums)
        max_num = max(nums)
        diff = max_num - min_num
        if diff <= 2 * k:
            return 0
        else:
            return diff - 2 * k