class Solution:
    def isPossibleToSplit(self, nums: List[int]) -> bool:
        n = len(nums)
        count = {}
        for num in nums:
            if num in count:
                count[num] += 1
            else:
                count[num] = 1
        for num in count:
            if count[num] > n // 2:
                return False
        return True