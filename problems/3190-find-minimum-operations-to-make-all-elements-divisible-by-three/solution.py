from typing import List

class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        ops = 0
        for num in nums:
            rem = num % 3
            if rem != 0:
                ops += min(rem, 3 - rem)
        return ops