class Solution {
public:
    string getSmallestString(string s) {
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if ((s[i] - '0') % 2 == (s[j] - '0') % 2 && s[j] < s[i]) {
                    swap(s[i], s[j]);
                    break;
                }
            }
        }
        return s;
    }
};