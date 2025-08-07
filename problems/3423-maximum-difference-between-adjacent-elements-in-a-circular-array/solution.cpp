class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int maxDiff = 0;
        for (int i = 0; i < nums.size() - 1; ++i) {
            maxDiff = std::max(maxDiff, std::abs(nums[i] - nums[i + 1]));
        }
        maxDiff = std::max(maxDiff, std::abs(nums[0] - nums[nums.size() - 1]));
        return maxDiff;
    }
};