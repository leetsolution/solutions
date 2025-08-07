class Solution {
    public int[] constructTransformedArray(int[] nums) {
        int n = nums.length;
        int[] result = new int[n];

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                int nextIndex = (i + nums[i]) % n;
                result[i] = nums[nextIndex >= 0 ? nextIndex : nextIndex + n];
            } else if (nums[i] < 0) {
                int nextIndex = (i + nums[i]) % n;
                result[i] = nums[nextIndex >= 0 ? nextIndex : nextIndex + n];
            } else {
                result[i] = nums[i];
            }
        }

        return result;
    }
}