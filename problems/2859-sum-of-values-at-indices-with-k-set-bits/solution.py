class Solution:
    def sumIndicesWithKSetBits(self, nums: List[int], k: int) -> int:
        total_sum = 0
        for i, num in enumerate(nums):
            binary = bin(i)[2:]
            set_bits = binary.count('1')
            if set_bits == k:
                total_sum += num
        return total_sum