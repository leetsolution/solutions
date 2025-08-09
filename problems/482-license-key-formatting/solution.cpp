class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string res = "";
        int count = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] != '-') {
                res += toupper(s[i]);
                count++;
                if (count == k) {
                    res += '-';
                    count = 0;
                }
            }
        }
        if (res.length() > 0 && res.back() == '-') {
            res.pop_back();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};