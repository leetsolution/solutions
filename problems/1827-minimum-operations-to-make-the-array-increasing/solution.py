class Solution:
    def minOperations(self, nums: list[int]) -> int:
        ops = 0
        for i in range(1, len(nums)):
            if nums[i] <= nums[i - 1]:
                diff = nums[i - 1] - nums[i] + 1
                ops += diff
                nums[i] += diff
        return ops