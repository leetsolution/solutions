class Solution {
public:
    bool hasMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        int starIndex = -1;
        for (int i = 0; i < m; ++i) {
            if (p[i] == '*') {
                starIndex = i;
                break;
            }
        }
        if (starIndex == -1) {
            return s.find(p) != string::npos;
        }
        for (int i = 0; i <= n - (m - 1); ++i) {
            bool match = true;
            for (int j = 0; j < starIndex; ++j) {
                if (s[i + j] != p[j]) {
                    match = false;
                    break;
                }
            }
            if (!match) continue;
            for (int j = 0; j < m - starIndex - 1; ++j) {
                if (s[i + starIndex + j + (n - (m - 1) - i)] != p[starIndex + j + 1]) {
                    match = false;
                    break;
                }
            }

            if(match)
                return true;
        }

        return false;
    }
};