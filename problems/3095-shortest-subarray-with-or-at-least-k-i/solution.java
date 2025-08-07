class Solution {
    public int minimumSubarrayLength(int[] nums, int k) {
        int minLen = Integer.MAX_VALUE;
        for (int i = 0; i < nums.length; i++) {
            int currentOr = 0;
            for (int j = i; j < nums.length; j++) {
                currentOr |= nums[j];
                if (currentOr >= k) {
                    minLen = Math.min(minLen, j - i + 1);
                    break;
                }
            }
        }
        return minLen == Integer.MAX_VALUE ? -1 : minLen;
    }
}