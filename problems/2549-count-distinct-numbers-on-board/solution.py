class Solution:
    def distinctIntegers(self, n: int) -> int:
        board = {n}
        added = True
        while added:
            added = False
            new_numbers = set()
            for x in board:
                for i in range(1, n + 1):
                    if x % i == 1 and i not in board:
                        new_numbers.add(i)
                        added = True
            board.update(new_numbers)
        return len(board)