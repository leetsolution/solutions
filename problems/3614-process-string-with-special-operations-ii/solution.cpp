class Solution {
public:
    char processStr(string s, long long k) {
    #include <string>
    #include <algorithm>

    char solve(std::string s, long long k) {
        std::string result = "";
        for (char c : s) {
            if (c >= 'a' && c <= 'z') {
                result += c;
            } else if (c == '*') {
                if (!result.empty()) {
                    result.pop_back();
                }
            } else if (c == '#') {
                result += result;
            } else if (c == '%') {
                std::reverse(result.begin(), result.end());
            }
        }
        if (k >= result.length() || k < 0) {
            return '.';
        }
        return result[k];
    }
};