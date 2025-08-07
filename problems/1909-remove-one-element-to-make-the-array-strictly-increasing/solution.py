class Solution:
    def canBeIncreasing(self, nums: List[int]) -> bool:
        n = len(nums)
        for i in range(n):
            temp = nums[:i] + nums[i+1:]
            is_increasing = True
            for j in range(1, len(temp)):
                if temp[j] <= temp[j-1]:
                    is_increasing = False
                    break
            if is_increasing:
                return True
        return False