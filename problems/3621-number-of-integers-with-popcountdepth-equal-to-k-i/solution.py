class Solution:
    def count_integers(n, k):
        def popcount_depth(x):
            depth = 0
            while x > 1:
                x = bin(x).count('1')
                depth += 1
            return depth

        count = 0
        for i in range(1, n + 1):
            if popcount_depth(i) == k:
                count += 1
        return count