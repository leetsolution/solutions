class Solution:
    def maximum_trionic_subarray(nums):
        n = len(nums)
        max_sum = float('-inf')

        for l in range(n - 3):
            for r in range(l + 3, n):
                for p in range(l + 1, r - 1):
                    for q in range(p + 1, r):
                        increasing1 = all(nums[l + i] < nums[l + i + 1] for i in range(p - l))
                        decreasing = all(nums[p + i] > nums[p + i + 1] for i in range(q - p))
                        increasing2 = all(nums[q + i] < nums[q + i + 1] for i in range(r - q))

                        if increasing1 and decreasing and increasing2:
                            current_sum = sum(nums[l:r])
                            max_sum = max(max_sum, current_sum)

        return max_sum