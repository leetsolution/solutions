class Solution:
    def bitwiseComplement(self, n: int) -> int:
        if n == 0:
            return 1
        num_bits = 0
        temp = n
        while temp > 0:
            num_bits += 1
            temp >>= 1
        mask = (1 << num_bits) - 1
        return n ^ mask