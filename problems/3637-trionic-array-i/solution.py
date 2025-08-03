class Solution:
    def isTrionic(nums):
        n = len(nums)
        for p in range(1, n - 1):
            for q in range(p + 1, n - 1):
                increasing1 = True
                for i in range(p):
                    if nums[i] >= nums[i + 1]:
                        increasing1 = False
                        break
                decreasing = True
                for i in range(p, q):
                    if nums[i] <= nums[i + 1]:
                        decreasing = False
                        break
                increasing2 = True
                for i in range(q, n - 1):
                    if nums[i] >= nums[i + 1]:
                        increasing2 = False
                        break
                if increasing1 and decreasing and increasing2:
                    return True
        return False