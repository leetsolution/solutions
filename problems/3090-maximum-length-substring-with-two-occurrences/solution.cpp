class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.length();
        int maxLength = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                string sub = s.substr(i, j - i + 1);
                bool valid = true;
                
                for (char c = 'a'; c <= 'z'; ++c) {
                    int count = 0;
                    for (char ch : sub) {
                        if (ch == c) {
                            count++;
                        }
                    }
                    if (count > 2) {
                        valid = false;
                        break;
                    }
                }

                if (valid) {
                    maxLength = max(maxLength, (int)sub.length());
                }
            }
        }

        return maxLength;
    }
};