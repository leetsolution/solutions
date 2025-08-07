class Solution:
    def winningPlayer(self, x: int, y: int) -> str:
        turns = 0
        while x >= 1 and y >= 4:
            x -= 1
            y -= 4
            turns += 1
        if turns % 2 == 0:
            return "Bob"
        else:
            return "Alice"