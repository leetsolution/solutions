class Solution {
public:
    bool checkOnesSegment(string s) {
        bool foundZero = false;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '0') {
                foundZero = true;
            } else if (foundZero && s[i] == '1') {
                return false;
            }
        }
        return true;
    }
};