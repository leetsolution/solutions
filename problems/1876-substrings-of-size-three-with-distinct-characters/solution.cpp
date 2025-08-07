class Solution {
public:
    int countGoodSubstrings(string s) {
        int count = 0;
        for (int i = 0; i <= s.length() - 3; i++) {
            string sub = s.substr(i, 3);
            if (sub[0] != sub[1] && sub[1] != sub[2] && sub[0] != sub[2]) {
                count++;
            }
        }
        return count;
    }
};