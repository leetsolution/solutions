class Solution:
    def addBinary(self, a: str, b: str) -> str:
        n = max(len(a), len(b))
        a = a.zfill(n)
        b = b.zfill(n)
        carry = 0
        result = ''
        for i in range(n - 1, -1, -1):
            digit_a = int(a[i])
            digit_b = int(b[i])
            sum_digits = digit_a + digit_b + carry
            result = str(sum_digits % 2) + result
            carry = sum_digits // 2
        if carry:
            result = '1' + result
        return result