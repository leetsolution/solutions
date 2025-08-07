class Solution {
public:
    vector<string> cellsInRange(string s) {
        vector<string> result;
        char col1 = s[0];
        int row1 = s[1] - '0';
        char col2 = s[3];
        int row2 = s[4] - '0';
        for (char c = col1; c <= col2; ++c) {
            for (int r = row1; r <= row2; ++r) {
                string cell = "";
                cell += c;
                cell += to_string(r);
                result.push_back(cell);
            }
        }
        return result;
    }
};