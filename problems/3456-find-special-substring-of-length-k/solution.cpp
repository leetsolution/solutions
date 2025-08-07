class Solution {
public:
    bool hasSpecialSubstring(string s, int k) {
        for (int i = 0; i <= s.length() - k; ++i) {
            char firstChar = s[i];
            bool allSame = true;
            for (int j = i; j < i + k; ++j) {
                if (s[j] != firstChar) {
                    allSame = false;
                    break;
                }
            }

            if (allSame) {
                bool beforeDifferent = true;
                if (i > 0) {
                    if (s[i - 1] == firstChar) {
                        beforeDifferent = false;
                    }
                }

                bool afterDifferent = true;
                if (i + k < s.length()) {
                    if (s[i + k] == firstChar) {
                        afterDifferent = false;
                    }
                }

                if (beforeDifferent && afterDifferent) {
                    return true;
                }
            }
        }
        return false;
    }
};