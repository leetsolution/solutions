class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        vector<pair<int, int>> rowStrengths(m);
        for (int i = 0; i < m; ++i) {
            int strength = 0;
            for (int j = 0; j < mat[i].size(); ++j) {
                if (mat[i][j] == 1) {
                    strength++;
                } else {
                    break;
                }
            }
            rowStrengths[i] = {strength, i};
        }
        
        sort(rowStrengths.begin(), rowStrengths.end());
        
        vector<int> result(k);
        for (int i = 0; i < k; ++i) {
            result[i] = rowStrengths[i].second;
        }
        
        return result;
    }
};