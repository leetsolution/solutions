class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_set<int> sums;
        for (int i = 0; i < nums.size() - 1; ++i) {
            int sum = nums[i] + nums[i + 1];
            if (sums.count(sum)) {
                return true;
            }
            sums.insert(sum);
        }
        return false;
    }
};