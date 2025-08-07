class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int maxLen = 0;
        for (int i = 0; i < s.length(); ++i) {
            for (int j = i + 1; j <= s.length(); ++j) {
                string sub = s.substr(i, j - i);
                int zeros = 0;
                int ones = 0;
                bool balanced = true;
                bool oneSeen = false;

                for (char c : sub) {
                    if (c == '0') {
                        if (oneSeen) {
                            balanced = false;
                            break;
                        }
                        zeros++;
                    } else {
                        oneSeen = true;
                        ones++;
                    }
                }

                if (balanced && zeros == ones) {
                    maxLen = max(maxLen, (int)sub.length());
                }
            }
        }
        return maxLen;
    }
};