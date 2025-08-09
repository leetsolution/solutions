class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        n = len(nums)
        seen = set()
        duplicate = -1
        sum_nums = 0
        expected_sum = n * (n + 1) // 2
        for num in nums:
            sum_nums += num
            if num in seen:
                duplicate = num
            seen.add(num)
        missing = expected_sum - sum_nums + duplicate
        return [duplicate, missing]