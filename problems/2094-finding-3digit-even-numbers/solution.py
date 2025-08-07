class Solution:
    def findEvenNumbers(self, digits: List[int]) -> List[int]:
        from collections import Counter
        count = Counter(digits)
        res = []
        for i in range(100, 1000, 2):
            s = str(i)
            c = Counter(s)
            flag = True
            for d in c:
                if count[int(d)] < c[d]:
                    flag = False
                    break
            if flag and s[0] != '0':
                res.append(i)
        return sorted(list(set(res)))