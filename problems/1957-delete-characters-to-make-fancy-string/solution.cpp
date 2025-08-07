class Solution {
public:
    string makeFancyString(string s) {
        string res = "";
        for (int i = 0; i < s.length(); ++i) {
            if (res.length() >= 2 && res[res.length() - 1] == s[i] && res[res.length() - 2] == s[i]) {
                continue;
            }
            res += s[i];
        }
        return res;
    }
};