class Solution:
    def findClosestNumber(self, nums: List[int]) -> int:
        closest = nums[0]
        min_diff = abs(nums[0])
        for num in nums:
            diff = abs(num)
            if diff < min_diff:
                min_diff = diff
                closest = num
            elif diff == min_diff:
                closest = max(closest, num)
        return closest