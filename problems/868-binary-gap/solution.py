class Solution:
    def binaryGap(self, n: int) -> int:
        binary = bin(n)[2:]
        indices = [i for i, bit in enumerate(binary) if bit == '1']
        if len(indices) < 2:
            return 0
        max_distance = 0
        for i in range(1, len(indices)):
            distance = indices[i] - indices[i - 1]
            max_distance = max(max_distance, distance)
        return max_distance