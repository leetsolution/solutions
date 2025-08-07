class Solution:
    def tictactoe(self, moves: List[List[int]]) -> str:
        grid = [['' for _ in range(3)] for _ in range(3)]
        A = 'A'
        B = 'B'
        turn = A
        for move in moves:
            row, col = move
            if turn == A:
                grid[row][col] = 'X'
                turn = B
            else:
                grid[row][col] = 'O'
                turn = A
        
        def check_winner(player):
            symbol = 'X' if player == A else 'O'
            for i in range(3):
                if all(grid[i][j] == symbol for j in range(3)):
                    return True
                if all(grid[j][i] == symbol for j in range(3)):
                    return True
            if all(grid[i][i] == symbol for i in range(3)):
                return True
            if all(grid[i][2 - i] == symbol for i in range(3)):
                return True
            return False
        
        if check_winner(A):
            return "A"
        if check_winner(B):
            return "B"
        
        if len(moves) == 9:
            return "Draw"
        else:
            return "Pending"