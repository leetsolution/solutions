class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int minVal = nums[0];
        int maxVal = nums[0];
        for (int num : nums) {
            minVal = min(minVal, num);
            maxVal = max(maxVal, num);
        }
        int range = maxVal - minVal;
        return max(0, range - 2 * k);
    }
};