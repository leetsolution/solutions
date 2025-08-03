class Solution:
    def minimum_removals(nums, k):
        nums.sort()
        n = len(nums)
        min_removals = n - 1
        for i in range(n):
            for j in range(i, n):
                sub_array = nums[i:j+1]
                if len(sub_array) > 0:
                    max_val = max(sub_array)
                    min_val = min(sub_array)
                    if max_val <= k * min_val:
                        removals = n - len(sub_array)
                        min_removals = min(min_removals, removals)
        return min_removals