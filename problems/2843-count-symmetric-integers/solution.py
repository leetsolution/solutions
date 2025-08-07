class Solution:
    def countSymmetricIntegers(self, low: int, high: int) -> int:
        count = 0
        for i in range(low, high + 1):
            s = str(i)
            n = len(s)
            if n % 2 == 0:
                mid = n // 2
                sum1 = sum(int(digit) for digit in s[:mid])
                sum2 = sum(int(digit) for digit in s[mid:])
                if sum1 == sum2:
                    count += 1
        return count