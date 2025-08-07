class Solution:
    def minStartValue(self, nums: List[int]) -> int:
        min_sum = 0
        current_sum = 0
        for num in nums:
            current_sum += num
            min_sum = min(min_sum, current_sum)
        
        if min_sum >= 0:
            return 1
        else:
            return abs(min_sum) + 1