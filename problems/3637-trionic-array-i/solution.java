class Solution {
    public boolean isTrionic(int[] nums) {
        int n = nums.length;
        for (int p = 1; p < n - 1; p++) {
            for (int q = p + 1; q < n - 1; q++) {
                boolean increasing1 = true;
                for (int i = 1; i <= p; i++) {
                    if (nums[i] <= nums[i - 1]) {
                        increasing1 = false;
                        break;
                    }
                }
                boolean decreasing2 = true;
                for (int i = p + 1; i <= q; i++) {
                    if (nums[i] >= nums[i - 1]) {
                        decreasing2 = false;
                        break;
                    }
                }
                boolean increasing3 = true;
                for (int i = q + 1; i < n; i++) {
                    if (nums[i] <= nums[i - 1]) {
                        increasing3 = false;
                        break;
                    }
                }
                if (increasing1 && decreasing2 && increasing3) {
                    return true;
                }
            }
        }
        return false;
    }
}