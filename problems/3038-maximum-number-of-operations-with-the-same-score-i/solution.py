class Solution:
    def maxOperations(self, nums: List[int]) -> int:
        if len(nums) < 2:
            return 0

        score = nums[0] + nums[1]
        count = 1
        i = 2

        while i < len(nums) - 1:
            if nums[i] + nums[i+1] == score:
                count += 1
                i += 2
            else:
                break
        return count