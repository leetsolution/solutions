class Solution:
    def findMinimumOperations(self, s1: str, s2: str, s3: str) -> int:
        i = len(s1) - 1
        j = len(s2) - 1
        k = len(s3) - 1
        count = 0
        while i >= 0 and j >= 0 and k >= 0:
            if s1[i] == s2[j] and s2[j] == s3[k]:
                i -= 1
                j -= 1
                k -= 1
            else:
                count += 1
                if i > j and i > k:
                    i -= 1
                elif j > i and j > k:
                    j -= 1
                elif k > i and k > j:
                    k -= 1
                else:
                    return -1
        if i == -1 and j == -1 and k == -1:
            return count
        else:
            return -1