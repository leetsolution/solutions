class Solution {
public:
    int maxPower(string s) {
        int max_len = 1;
        int curr_len = 1;
        for (int i = 1; i < s.length(); ++i) {
            if (s[i] == s[i - 1]) {
                curr_len++;
            } else {
                max_len = max(max_len, curr_len);
                curr_len = 1;
            }
        }
        max_len = max(max_len, curr_len);
        return max_len;
    }
};