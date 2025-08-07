class Solution:
    def largestInteger(self, num: int) -> int:
        s = str(num)
        odds = sorted([int(c) for i, c in enumerate(s) if int(c) % 2], reverse=True)
        evens = sorted([int(c) for i, c in enumerate(s) if int(c) % 2 == 0], reverse=True)
        o_idx = 0
        e_idx = 0
        res = ""
        for i, c in enumerate(s):
            if int(c) % 2:
                res += str(odds[o_idx])
                o_idx += 1
            else:
                res += str(evens[e_idx])
                e_idx += 1
        return int(res)