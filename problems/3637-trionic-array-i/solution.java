class Solution {
    public boolean isTrionic(int[] nums) {
        int n = nums.length;
        for (int p = 1; p < n - 1; p++) {
            for (int q = p + 1; q < n; q++) {
                boolean increasing1 = true;
                for (int i = 1; i <= p; i++) {
                    if (nums[i] <= nums[i - 1]) {
                        increasing1 = false;
                        break;
                    }
                }
                if (!increasing1) continue;

                boolean decreasing = true;
                for (int i = p + 1; i <= q; i++) {
                    if (nums[i] >= nums[i - 1]) {
                        decreasing = false;
                        break;
                    }
                }
                if (!decreasing) continue;

                boolean increasing2 = true;
                for (int i = q + 1; i < n; i++) {
                    if (nums[i] <= nums[i - 1]) {
                        increasing2 = false;
                        break;
                    }
                }
                if (!increasing2) continue;

                return true;
            }
        }
        return false;
    }
}