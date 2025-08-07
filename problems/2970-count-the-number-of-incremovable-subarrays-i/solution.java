class Solution {
    public int incremovableSubarrayCount(int[] nums) {
        int n = nums.length;
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (isIncremovable(nums, i, j)) {
                    count++;
                }
            }
        }
        return count;
    }

    private boolean isIncremovable(int[] nums, int start, int end) {
        int n = nums.length;
        int[] remaining = new int[n - (end - start + 1)];
        int index = 0;
        for (int i = 0; i < start; i++) {
            remaining[index++] = nums[i];
        }
        for (int i = end + 1; i < n; i++) {
            remaining[index++] = nums[i];
        }

        if (remaining.length == 0) {
            return true;
        }

        for (int i = 1; i < remaining.length; i++) {
            if (remaining[i] <= remaining[i - 1]) {
                return false;
            }
        }
        return true;
    }
}