class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int rook_row, rook_col;
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                if (board[i][j] == 'R') {
                    rook_row = i;
                    rook_col = j;
                    break;
                }
            }
        }

        int captures = 0;

        for (int i = rook_row - 1; i >= 0; --i) {
            if (board[i][rook_col] == 'p') {
                captures++;
                break;
            } else if (board[i][rook_col] == 'B') {
                break;
            }
        }

        for (int i = rook_row + 1; i < 8; ++i) {
            if (board[i][rook_col] == 'p') {
                captures++;
                break;
            } else if (board[i][rook_col] == 'B') {
                break;
            }
        }

        for (int j = rook_col - 1; j >= 0; --j) {
            if (board[rook_row][j] == 'p') {
                captures++;
                break;
            } else if (board[rook_row][j] == 'B') {
                break;
            }
        }

        for (int j = rook_col + 1; j < 8; ++j) {
            if (board[rook_row][j] == 'p') {
                captures++;
                break;
            } else if (board[rook_row][j] == 'B') {
                break;
            }
        }

        return captures;
    }
};