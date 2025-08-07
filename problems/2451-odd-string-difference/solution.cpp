class Solution {
public:
    string oddString(vector<string>& words) {
        int n = words.size();
        int len = words[0].length();
        vector<vector<int>> diffs(n, vector<int>(len - 1));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < len - 1; ++j) {
                diffs[i][j] = words[i][j + 1] - words[i][j];
            }
        }

        if (diffs[0] == diffs[1]) {
            for (int i = 2; i < n; ++i) {
                if (diffs[i] != diffs[0]) {
                    return words[i];
                }
            }
        } else {
            if (diffs[0] == diffs[2]) {
                return words[1];
            } else {
                return words[0];
            }
        }
        return "";
    }
};