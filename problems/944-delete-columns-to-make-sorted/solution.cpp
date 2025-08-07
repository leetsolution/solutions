class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int len = strs[0].length();
        int count = 0;
        for (int j = 0; j < len; ++j) {
            for (int i = 1; i < n; ++i) {
                if (strs[i][j] < strs[i - 1][j]) {
                    count++;
                    break;
                }
            }
        }
        return count;
    }
};