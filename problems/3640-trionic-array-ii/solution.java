class Solution {
    public long maxSumTrionic(int[] nums) {
    class Solution {
        public long maximumTrionicSubarraySum(int[] nums) {
            long maxSum = Long.MIN_VALUE;
            int n = nums.length;

            for (int l = 0; l < n - 2; l++) {
                for (int r = l + 2; r < n; r++) {
                    for (int p = l + 1; p < r; p++) {
                        for (int q = p + 1; q < r; q++) {
                            boolean increasing1 = true;
                            for (int i = l + 1; i <= p; i++) {
                                if (nums[i] <= nums[i - 1]) {
                                    increasing1 = false;
                                    break;
                                }
                            }

                            boolean decreasing = true;
                            for (int i = p + 1; i <= q; i++) {
                                if (nums[i] >= nums[i - 1]) {
                                    decreasing = false;
                                    break;
                                }
                            }

                            boolean increasing2 = true;
                            for (int i = q + 1; i <= r; i++) {
                                if (nums[i] <= nums[i - 1]) {
                                    increasing2 = false;
                                    break;
                                }
                            }

                            if (increasing1 && decreasing && increasing2) {
                                long currentSum = 0;
                                for (int i = l; i <= r; i++) {
                                    currentSum += nums[i];
                                }
                                maxSum = Math.max(maxSum, currentSum);
                            }
                        }
                    }
                }
            }
            return maxSum;
        }
    }
}