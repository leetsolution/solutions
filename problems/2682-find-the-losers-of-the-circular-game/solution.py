class Solution:
    def circularGameLosers(self, n: int, k: int) -> List[int]:
        received = [False] * n
        curr = 0
        received[curr] = True
        i = 1
        while True:
            curr = (curr + i * k) % n
            if received[curr]:
                break
            received[curr] = True
            i += 1
        losers = []
        for j in range(n):
            if not received[j]:
                losers.append(j + 1)
        return losers