class Solution:
    def minRemoval(self, nums: List[int], k: int) -> int:
        nums.sort()
        n = len(nums)
        max_len = 0
        l = 0
        for r in range(n):
            while nums[r] > nums[l] * k:
                l += 1
            max_len = max(max_len, r - l + 1)
        return n - max_len