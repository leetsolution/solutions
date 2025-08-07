import java.util.Arrays;

class Solution {
    public double minimumAverage(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;
        double[] averages = new double[n / 2];
        for (int i = 0; i < n / 2; i++) {
            averages[i] = (double) (nums[i] + nums[n - 1 - i]) / 2;
        }
        double minAvg = averages[0];
        for (int i = 1; i < n / 2; i++) {
            minAvg = Math.min(minAvg, averages[i]);
        }
        return minAvg;
    }
}