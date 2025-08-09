class Solution {
public:
    bool checkRecord(string s) {
        int absentCount = 0;
        int lateCount = 0;
        for (char c : s) {
            if (c == 'A') {
                absentCount++;
            } else if (c == 'L') {
                lateCount++;
            } else {
                lateCount = 0;
            }
            if (absentCount >= 2 || lateCount >= 3) {
                return false;
            }
        }
        return true;
    }
};