class Solution {
public:
    bool isSubstringPresent(string s) {
        if (s.length() < 2) {
            return false;
        }
        string reversed_s = s;
        reverse(reversed_s.begin(), reversed_s.end());
        for (int i = 0; i < s.length() - 1; ++i) {
            string sub = s.substr(i, 2);
            if (reversed_s.find(sub) != string::npos) {
                return true;
            }
        }
        return false;
    }
};