class Solution:
    def sumOfMultiples(self, n: int) -> int:
        s = set()
        for i in range(3, n + 1, 3):
            s.add(i)
        for i in range(5, n + 1, 5):
            s.add(i)
        for i in range(7, n + 1, 7):
            s.add(i)
        return sum(s)