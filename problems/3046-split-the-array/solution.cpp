class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }
        for (auto const& [key, val] : count) {
            if (val > n / 2) {
                return false;
            }
        }
        return true;
    }
};