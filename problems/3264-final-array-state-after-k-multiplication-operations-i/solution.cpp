class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        for (int i = 0; i < k; ++i) {
            int minVal = nums[0];
            int minIndex = 0;
            for (int j = 1; j < nums.size(); ++j) {
                if (nums[j] < minVal) {
                    minVal = nums[j];
                    minIndex = j;
                }
            }
            nums[minIndex] *= multiplier;
        }
        return nums;
    }
};