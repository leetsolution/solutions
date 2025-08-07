class Solution {
public:
    int minimumMoves(string s) {
        int n = s.length();
        int moves = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'X') {
                moves++;
                i += 2;
            }
        }
        return moves;
    }
};