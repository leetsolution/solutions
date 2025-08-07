class Solution:
    def countLargestGroup(self, n: int) -> int:
        groups = {}
        for i in range(1, n + 1):
            s = 0
            temp = i
            while temp > 0:
                s += temp % 10
                temp //= 10
            if s not in groups:
                groups[s] = 0
            groups[s] += 1

        max_size = 0
        count = 0
        for size in groups.values():
            if size > max_size:
                max_size = size
                count = 1
            elif size == max_size:
                count += 1

        return count