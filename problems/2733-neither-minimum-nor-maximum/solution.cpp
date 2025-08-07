class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        if (nums.size() <= 2) {
            return -1;
        }
        int minVal = nums[0];
        int maxVal = nums[0];
        for (int num : nums) {
            minVal = min(minVal, num);
            maxVal = max(maxVal, num);
        }
        for (int num : nums) {
            if (num != minVal && num != maxVal) {
                return num;
            }
        }
        return -1;
    }
};