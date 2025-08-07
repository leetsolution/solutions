class Solution:
    def canAliceWin(self, n: int) -> bool:
        if n < 10:
            return False
        n -= 10
        turn = 11
        alice = False
        while n >= turn - 1:
            n -= (turn - 1)
            turn += 1
            if n < turn - 1:
                alice = True
                break
            n -= (turn - 1)
            turn += 1
            if n < turn - 1:
                alice = False
                break
        return alice