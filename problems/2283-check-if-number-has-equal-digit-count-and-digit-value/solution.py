class Solution:
    def digitCount(self, num: str) -> bool:
        n = len(num)
        for i in range(n):
            count = 0
            for j in range(n):
                if int(num[j]) == i:
                    count += 1
            if count != int(num[i]):
                return False
        return True