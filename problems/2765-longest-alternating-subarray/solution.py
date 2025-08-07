class Solution:
    def alternatingSubarray(self, nums: List[int]) -> int:
        max_len = -1
        for i in range(len(nums) - 1):
            for j in range(i + 1, len(nums)):
                length = j - i + 1
                if length > 1:
                    valid = True
                    for k in range(i + 1, j + 1):
                        if nums[k] - nums[k - 1] != (-1)**(k - i):
                            valid = False
                            break
                    if valid:
                        max_len = max(max_len, length)
        return max_len