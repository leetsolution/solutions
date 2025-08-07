class Solution {
    public int findClosestNumber(int[] nums) {
        int closest = nums[0];
        int minDiff = Math.abs(nums[0]);

        for (int i = 1; i < nums.length; i++) {
            int diff = Math.abs(nums[i]);

            if (diff < minDiff) {
                minDiff = diff;
                closest = nums[i];
            } else if (diff == minDiff) {
                closest = Math.max(closest, nums[i]);
            }
        }

        return closest;
    }
}