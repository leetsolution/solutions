class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int, int>> indexedNums;
        for (int i = 0; i < nums.size(); ++i) {
            indexedNums.push_back({nums[i], i});
        }

        sort(indexedNums.begin(), indexedNums.end(), greater<pair<int, int>>());

        vector<pair<int, int>> topK;
        for (int i = 0; i < k; ++i) {
            topK.push_back(indexedNums[i]);
        }

        sort(topK.begin(), topK.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second < b.second;
        });

        vector<int> result;
        for (int i = 0; i < k; ++i) {
            result.push_back(topK[i].first);
        }

        return result;
    }
};