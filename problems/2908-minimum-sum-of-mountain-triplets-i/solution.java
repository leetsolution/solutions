class Solution {
    public int minimumSum(int[] nums) {
        int n = nums.length;
        int minSum = Integer.MAX_VALUE;

        for (int j = 1; j < n - 1; j++) {
            int iMin = Integer.MAX_VALUE;
            for (int i = 0; i < j; i++) {
                if (nums[i] < nums[j]) {
                    iMin = Math.min(iMin, nums[i]);
                }
            }

            int kMin = Integer.MAX_VALUE;
            for (int k = j + 1; k < n; k++) {
                if (nums[k] < nums[j]) {
                    kMin = Math.min(kMin, nums[k]);
                }
            }

            if (iMin != Integer.MAX_VALUE && kMin != Integer.MAX_VALUE) {
                minSum = Math.min(minSum, iMin + nums[j] + kMin);
            }
        }

        if (minSum == Integer.MAX_VALUE) {
            return -1;
        }

        return minSum;
    }
}