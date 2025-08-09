class Solution:
    def minSwaps(self, nums: List[int]) -> int:
        n = len(nums)
        odd_count = sum(1 for num in nums if num % 2 != 0)
        even_count = n - odd_count

        if abs(odd_count - even_count) > 1:
            return -1

        def calculate_swaps(start_with_even):
            swaps = 0
            temp_nums = nums[:]
            even_idx = 0
            odd_idx = 0
            
            if start_with_even:
                expected = 0
            else:
                expected = 1

            for i in range(n):
                if temp_nums[i] % 2 == expected:
                    expected = 1 - expected
                    continue
                else:
                    j = i + 1
                    while j < n and temp_nums[j] % 2 != expected:
                        j += 1
                    if j == n:
                        return float('inf')

                    swaps += (j - i)
                    temp_nums[i:j+1] = [temp_nums[j]] + temp_nums[i:j]
                    expected = 1 - expected
            return swaps
        
        if odd_count > even_count:
            return calculate_swaps(False)
        elif even_count > odd_count:
            return calculate_swaps(True)
        else:
            return min(calculate_swaps(True), calculate_swaps(False))