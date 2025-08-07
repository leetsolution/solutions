class Solution {
public:
    string winningPlayer(int x, int y) {
        int turns = 0;
        while (x >= 1 && y >= 4) {
            x--;
            y -= 4;
            turns++;
        }
        if (x == 0 && y >= 11)
        {
            turns += y/11;
            y %= 11;
        }
        if (turns % 2 == 1) {
            return "Alice";
        } else {
            return "Bob";
        }
    }
};