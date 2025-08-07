class Solution:
    def maxSum(self, nums: List[int]) -> int:
        def largest_digit(n):
            max_digit = 0
            while n > 0:
                digit = n % 10
                max_digit = max(max_digit, digit)
                n //= 10
            return max_digit

        max_sum = -1
        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                if largest_digit(nums[i]) == largest_digit(nums[j]):
                    max_sum = max(max_sum, nums[i] + nums[j])

        return max_sum