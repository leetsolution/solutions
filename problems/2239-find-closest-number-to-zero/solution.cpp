class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int closest = nums[0];
        int min_diff = abs(nums[0]);
        for (int i = 1; i < nums.size(); ++i) {
            int diff = abs(nums[i]);
            if (diff < min_diff) {
                min_diff = diff;
                closest = nums[i];
            } else if (diff == min_diff) {
                closest = max(closest, nums[i]);
            }
        }
        return closest;
    }
};