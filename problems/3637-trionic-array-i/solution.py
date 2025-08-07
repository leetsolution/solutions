class Solution:
    def isTrionic(self, nums: List[int]) -> bool:
        n = len(nums)
        for p in range(1, n - 1):
            for q in range(p + 1, n):
                increasing1 = True
                for i in range(p - 1):
                    if nums[i] >= nums[i + 1]:
                        increasing1 = False
                        break
                if not increasing1:
                    continue

                decreasing = True
                for i in range(p, q - 1):
                    if nums[i] <= nums[i + 1]:
                        decreasing = False
                        break
                if not decreasing:
                    continue

                increasing2 = True
                for i in range(q, n - 1):
                    if nums[i] >= nums[i + 1]:
                        increasing2 = False
                        break
                if not increasing2:
                    continue

                return True

        return False