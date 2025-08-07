from typing import List

class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        s = sum(nums)
        return (s % k) if (s % k) != 0 else 0