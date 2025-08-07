class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int lines = 1;
        int width = 0;
        for (char c : s) {
            int w = widths[c - 'a'];
            if (width + w <= 100) {
                width += w;
            } else {
                lines++;
                width = w;
            }
        }
        return {lines, width};
    }
};