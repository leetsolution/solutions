class Solution {
public:
    string resultingString(string s) {
        string res = "";
        for (char c : s) {
            if (!res.empty() && ((abs(res.back() - c) == 1) || (res.back() == 'a' && c == 'z') || (res.back() == 'z' && c == 'a'))) {
                res.pop_back();
            } else {
                res.push_back(c);
            }
        }
        return res;
    }
};