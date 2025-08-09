class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        for (int i = 1; i <= n / 2; ++i) {
            if (n % i == 0) {
                string sub = s.substr(0, i);
                bool match = true;
                for (int j = i; j < n; j += i) {
                    if (s.substr(j, i) != sub) {
                        match = false;
                        break;
                    }
                }
                if (match) return true;
            }
        }
        return false;
    }
};