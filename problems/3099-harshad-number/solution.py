class Solution:
    def sumOfTheDigitsOfHarshadNumber(self, x: int) -> int:
        s = 0
        temp = x
        while temp > 0:
            s += temp % 10
            temp //= 10
        if s == 0:
            return -1
        if x % s == 0:
            return s
        else:
            return -1