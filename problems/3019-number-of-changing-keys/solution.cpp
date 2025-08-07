class Solution {
public:
    int countKeyChanges(string s) {
        int count = 0;
        if (s.length() <= 1) return 0;
        for (int i = 1; i < s.length(); ++i) {
            char prev = tolower(s[i - 1]);
            char curr = tolower(s[i]);
            if (prev != curr) {
                count++;
            }
        }
        return count;
    }
};