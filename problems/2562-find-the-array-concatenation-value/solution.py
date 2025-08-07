class Solution:
    def findTheArrayConcVal(self, nums: List[int]) -> int:
        concatenation_value = 0
        left = 0
        right = len(nums) - 1
        while left <= right:
            if left == right:
                concatenation_value += nums[left]
                break
            else:
                concatenation_value += int(str(nums[left]) + str(nums[right]))
                left += 1
                right -= 1
        return concatenation_value