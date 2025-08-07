class Solution {
    public int findNonMinOrMax(int[] nums) {
        if (nums.length <= 2) {
            return -1;
        }
        int minVal = nums[0];
        int maxVal = nums[0];
        for (int num : nums) {
            minVal = Math.min(minVal, num);
            maxVal = Math.max(maxVal, num);
        }
        for (int num : nums) {
            if (num != minVal && num != maxVal) {
                return num;
            }
        }
        return -1;
    }
}