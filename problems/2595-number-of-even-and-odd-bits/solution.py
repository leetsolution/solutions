class Solution:
    def evenOddBit(self, n: int) -> List[int]:
        binary = bin(n)[2:]
        even = 0
        odd = 0
        for i in range(len(binary)):
            if int(binary[i]) == 1:
                if (len(binary) - 1 - i) % 2 == 0:
                    even += 1
                else:
                    odd += 1
        return [even, odd]