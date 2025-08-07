class Solution:
    def minElement(self, nums: List[int]) -> int:
        min_num = float('inf')
        for num in nums:
            digit_sum = 0
            temp = num
            while temp > 0:
                digit_sum += temp % 10
                temp //= 10
            min_num = min(min_num, digit_sum)
        return min_num