class Solution:
    def minimumRightShifts(self, nums: List[int]) -> int:
        n = len(nums)
        for shifts in range(n):
            temp = nums[:]
            for _ in range(shifts):
                last = temp[-1]
                for i in range(n - 1, 0, -1):
                    temp[i] = temp[i - 1]
                temp[0] = last
            
            if all(temp[i] <= temp[i+1] for i in range(n-1)):
                return shifts
        return -1