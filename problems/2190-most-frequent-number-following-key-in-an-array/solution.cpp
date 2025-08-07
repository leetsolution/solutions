class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        unordered_map<int, int> count;
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] == key) {
                count[nums[i + 1]]++;
            }
        }
        int maxCount = 0;
        int result = -1;
        for (auto const& [key, val] : count) {
            if (val > maxCount) {
                maxCount = val;
                result = key;
            }
        }
        return result;
    }
};