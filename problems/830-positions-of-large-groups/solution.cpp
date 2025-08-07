class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> result;
        if (s.empty()) return result;
        char currentChar = s[0];
        int count = 1;
        int start = 0;
        for (int i = 1; i < s.length(); ++i) {
            if (s[i] == currentChar) {
                count++;
            } else {
                if (count >= 3) {
                    result.push_back({start, i - 1});
                }
                currentChar = s[i];
                count = 1;
                start = i;
            }
        }
        if (count >= 3) {
            result.push_back({start, (int)s.length() - 1});
        }
        return result;
    }
};