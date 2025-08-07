class Solution {
    public int maximizeSum(int[] nums, int k) {
        int maxVal = 0;
        for (int num : nums) {
            maxVal = Math.max(maxVal, num);
        }
        int sum = 0;
        for (int i = 0; i < k; i++) {
            sum += maxVal;
            maxVal++;
        }
        return sum;
    }
}