class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        unordered_map<int, int> counts;
        for (const auto& vec : nums) {
            for (int num : vec) {
                counts[num]++;
            }
        }
        vector<int> result;
        int n = nums.size();
        for (const auto& pair : counts) {
            if (pair.second == n) {
                result.push_back(pair.first);
            }
        }
        sort(result.begin(), result.end());
        return result;
    }
};