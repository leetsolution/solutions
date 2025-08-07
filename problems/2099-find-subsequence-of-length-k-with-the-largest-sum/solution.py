from typing import List

class Solution:
    def maxSubsequence(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        indexed_nums = sorted([(nums[i], i) for i in range(n)], reverse=True)
        top_k_indices = sorted([indexed_nums[i][1] for i in range(k)])
        result = [nums[i] for i in top_k_indices]
        return result