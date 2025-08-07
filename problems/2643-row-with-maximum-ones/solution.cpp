class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int max_ones = 0;
        int row_index = 0;
        for (int i = 0; i < mat.size(); ++i) {
            int ones = 0;
            for (int j = 0; j < mat[i].size(); ++j) {
                if (mat[i][j] == 1) {
                    ones++;
                }
            }
            if (ones > max_ones) {
                max_ones = ones;
                row_index = i;
            }
        }
        return {row_index, max_ones};
    }
};