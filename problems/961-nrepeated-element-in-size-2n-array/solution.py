class Solution:
    def repeatedNTimes(self, nums: List[int]) -> int:
        count = {}
        for num in nums:
            if num in count:
                return num
            else:
                count[num] = 1