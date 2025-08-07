class Solution:
    def distinctAverages(self, nums: list[int]) -> int:
        nums.sort()
        averages = set()
        left, right = 0, len(nums) - 1
        while left < right:
            averages.add((nums[left] + nums[right]) / 2)
            left += 1
            right -= 1
        return len(averages)