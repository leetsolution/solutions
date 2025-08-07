class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size() / 2;
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] == nums[i + 1]) {
                return nums[i];
            }
        }
        for (int i = 0; i < nums.size() - 2; ++i) {
            if (nums[i] == nums[i + 2]) {
                return nums[i];
            }
        }
        return nums[0];
    }
};