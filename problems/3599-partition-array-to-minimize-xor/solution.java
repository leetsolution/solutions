class Solution {
    public int minXor(int[] nums, int k) {
        int n = nums.length;
        int low = 0, high = 0;
        for (int num : nums) {
            high = Math.max(high, num);
        }
        int ans = high;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (possible(nums, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    private boolean possible(int[] nums, int k, int target) {
        int count = 1;
        int xor = 0;
        for (int num : nums) {
            xor ^= num;
            if (xor > target) {
                count++;
                xor = num;
            }
        }
        return count <= k;
    }
}