class Solution {
public:
    int countElements(vector<int>& nums) {
        if (nums.size() < 3) {
            return 0;
        }
        
        int minVal = nums[0];
        int maxVal = nums[0];
        
        for (int num : nums) {
            minVal = min(minVal, num);
            maxVal = max(maxVal, num);
        }
        
        int count = 0;
        for (int num : nums) {
            if (num > minVal && num < maxVal) {
                count++;
            }
        }
        
        return count;
    }
};