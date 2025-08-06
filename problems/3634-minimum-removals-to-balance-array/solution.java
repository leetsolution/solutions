class Solution {
    public int minRemoval(int[] nums, int k) {
    import java.util.Arrays;

    class Solution {
        public int minimumRemovals(int[] nums, int k) {
            Arrays.sort(nums);
            int n = nums.length;
            int minRemovals = n - 1;

            for (int i = 0; i < n; i++) {
                int minVal = nums[i];
                int maxVal = -1;
                int count = 0;
                for (int j = i; j < n; j++) {
                    maxVal = Math.max(maxVal, nums[j]);
                    if (maxVal <= minVal * k) {
                        count = j - i + 1;
                        minRemovals = Math.min(minRemovals, n - count);
                    } else {
                        break;
                    }
                }
            }

            return minRemovals;
        }
    }
}