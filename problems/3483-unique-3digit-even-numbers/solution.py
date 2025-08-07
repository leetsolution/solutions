class Solution:
    def totalNumbers(self, digits: List[int]) -> int:
        import itertools
        count = 0
        s = set()
        for i in itertools.permutations(digits, 3):
            if i[0] != 0 and i[2] % 2 == 0:
                num = i[0] * 100 + i[1] * 10 + i[2]
                if num not in s:
                    count += 1
                    s.add(num)
        return count