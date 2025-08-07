class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int currentPos = 0;
        for (const string& command : commands) {
            if (command == "UP") {
                currentPos -= n;
            } else if (command == "DOWN") {
                currentPos += n;
            } else if (command == "RIGHT") {
                currentPos++;
            } else {
                currentPos--;
            }
        }
        return currentPos;
    }
};