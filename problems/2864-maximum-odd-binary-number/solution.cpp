class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int ones = 0;
        int zeros = 0;
        for (char c : s) {
            if (c == '1') {
                ones++;
            } else {
                zeros++;
            }
        }

        string result = "";
        for (int i = 0; i < ones - 1; ++i) {
            result += '1';
        }
        for (int i = 0; i < zeros; ++i) {
            result += '0';
        }
        result += '1';

        return result;
    }
};