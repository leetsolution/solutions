class Solution:
    def subarraySum(self, nums: List[int]) -> int:
        total_sum = 0
        for i in range(len(nums)):
            start = max(0, i - nums[i])
            sub_array_sum = sum(nums[start:i+1])
            total_sum += sub_array_sum
        return total_sum