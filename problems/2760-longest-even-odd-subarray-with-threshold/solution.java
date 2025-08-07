class Solution {
    public int longestAlternatingSubarray(int[] nums, int threshold) {
        int maxLen = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] % 2 == 0 && nums[i] <= threshold) {
                int currentLen = 1;
                for (int j = i + 1; j < nums.length; j++) {
                    if (nums[j] <= threshold && nums[j] % 2 != nums[j - 1] % 2) {
                        currentLen++;
                    } else {
                        break;
                    }
                }
                maxLen = Math.max(maxLen, currentLen);
            }
        }
        return maxLen;
    }
}