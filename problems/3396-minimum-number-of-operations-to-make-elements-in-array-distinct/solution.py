class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 0:
            return 0

        for ops in range((n + 2) // 3 + 1):
            remaining = nums[ops * 3:]
            if len(set(remaining)) == len(remaining):
                return ops
            if len(remaining) == 0:
                return ops