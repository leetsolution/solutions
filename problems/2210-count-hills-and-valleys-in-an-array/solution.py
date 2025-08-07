class Solution:
    def countHillValley(self, nums: List[int]) -> int:
        count = 0
        for i in range(1, len(nums) - 1):
            left = i - 1
            right = i + 1
            while left >= 0 and nums[left] == nums[i]:
                left -= 1
            while right < len(nums) and nums[right] == nums[i]:
                right += 1
            if left >= 0 and right < len(nums):
                if (nums[i] > nums[left] and nums[i] > nums[right]) or \
                   (nums[i] < nums[left] and nums[i] < nums[right]):
                    count += 1
        return count