class Solution:
    def smallestIndex(self, nums: List[int]) -> int:
        for i in range(len(nums)):
            s = 0
            num = nums[i]
            str_num = str(num)
            for digit in str_num:
                s += int(digit)
            if s == i:
                return i
        return -1