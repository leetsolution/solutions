class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<pair<int, int>> pairs;
        for (int i = 0; i < n; ++i) {
            pairs.push_back({score[i], i});
        }
        sort(pairs.rbegin(), pairs.rend());
        vector<string> result(n);
        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                result[pairs[i].second] = "Gold Medal";
            } else if (i == 1) {
                result[pairs[i].second] = "Silver Medal";
            } else if (i == 2) {
                result[pairs[i].second] = "Bronze Medal";
            } else {
                result[pairs[i].second] = to_string(i + 1);
            }
        }
        return result;
    }
};