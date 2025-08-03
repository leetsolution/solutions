import java.util.Arrays;

class Solution {
    public int minRemoval(int[] nums, int k) {
        Arrays.sort(nums);
        int n = nums.length;
        int minRemovals = n - 1;
        for (int i = 0; i < n; i++) {
            int minVal = nums[i];
            int maxVal = nums[n - 1];
            int left = i;
            int right = n - 1;
            int count = 0;
            while (left <= right) {
                if (maxVal <= minVal * k) {
                    minRemovals = Math.min(minRemovals, count);
                    break;
                }
                count++;
                right--;
                maxVal = nums[right];
            }
        }
        return minRemovals;
    }
}