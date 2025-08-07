class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        string prefix = "";
        for (string word : words) {
            prefix += word;
            if (prefix == s) {
                return true;
            } else if (prefix.length() > s.length()) {
                return false;
            }
        }
        return false;
    }
};