class Solution:
    def sortArrayByParityII(self, nums: List[int]) -> List[int]:
        odd_idx = 1
        even_idx = 0
        while odd_idx < len(nums) and even_idx < len(nums):
            if nums[even_idx] % 2 == 0:
                even_idx += 2
            elif nums[odd_idx] % 2 != 0:
                odd_idx += 2
            else:
                nums[even_idx], nums[odd_idx] = nums[odd_idx], nums[even_idx]
                even_idx += 2
                odd_idx += 2
        return nums