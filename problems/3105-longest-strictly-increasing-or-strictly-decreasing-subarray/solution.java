class Solution {
    public int longestMonotonicSubarray(int[] nums) {
        int n = nums.length;
        if (n <= 1) {
            return n;
        }
        int maxLength = 1;
        for (int i = 0; i < n; i++) {
            int increasingLength = 1;
            for (int j = i + 1; j < n; j++) {
                if (nums[j] > nums[j - 1]) {
                    increasingLength++;
                } else {
                    break;
                }
            }
            maxLength = Math.max(maxLength, increasingLength);

            int decreasingLength = 1;
            for (int j = i + 1; j < n; j++) {
                if (nums[j] < nums[j - 1]) {
                    decreasingLength++;
                } else {
                    break;
                }
            }
            maxLength = Math.max(maxLength, decreasingLength);
        }
        return maxLength;
    }
}