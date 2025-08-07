class Solution:
    def fairCandySwap(self, aliceSizes: List[int], bobSizes: List[int]) -> List[int]:
        sum_alice = sum(aliceSizes)
        sum_bob = sum(bobSizes)
        set_bob = set(bobSizes)
        for x in aliceSizes:
            y = (sum_bob - sum_alice + 2 * x) // 2
            if y in set_bob:
                return [x, y]