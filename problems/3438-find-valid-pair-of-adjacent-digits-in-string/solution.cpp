class Solution {
public:
    string findValidPair(string s) {
        int counts[10] = {0};
        for (char c : s) {
            counts[c - '0']++;
        }

        for (int i = 0; i < s.length() - 1; ++i) {
            if (s[i] != s[i+1]) {
                int firstDigit = s[i] - '0';
                int secondDigit = s[i+1] - '0';

                if (counts[firstDigit] == firstDigit && counts[secondDigit] == secondDigit) {
                    return string(1, s[i]) + string(1, s[i+1]);
                }
            }
        }

        return "";
    }
};