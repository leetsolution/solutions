class Solution:
    def incremovableSubarrayCount(self, nums: List[int]) -> int:
        n = len(nums)
        count = 0
        for i in range(n):
            for j in range(i, n):
                temp = nums[:i] + nums[j+1:]
                if len(temp) == 0:
                    count += 1
                    continue
                increasing = True
                for k in range(len(temp) - 1):
                    if temp[k] >= temp[k+1]:
                        increasing = False
                        break
                if increasing:
                    count += 1
        return count