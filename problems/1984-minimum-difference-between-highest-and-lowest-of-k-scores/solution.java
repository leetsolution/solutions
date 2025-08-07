import java.util.Arrays;

class Solution {
    public int minimumDifference(int[] nums, int k) {
        if (k == 1) {
            return 0;
        }
        Arrays.sort(nums);
        int minDifference = Integer.MAX_VALUE;
        for (int i = 0; i <= nums.length - k; i++) {
            int difference = nums[i + k - 1] - nums[i];
            minDifference = Math.min(minDifference, difference);
        }
        return minDifference;
    }
}