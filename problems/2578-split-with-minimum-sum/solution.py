class Solution:
    def splitNum(self, num: int) -> int:
        s = sorted(str(num))
        n1 = ""
        n2 = ""
        for i in range(len(s)):
            if i % 2 == 0:
                n1 += s[i]
            else:
                n2 += s[i]
        return int(n1) + int(n2)