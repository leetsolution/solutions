import java.util.Arrays;

class Solution {
    public int minRemoval(int[] nums, int k) {
        Arrays.sort(nums);
        int n = nums.length;
        int maxLen = 0;
        for (int i = 0; i < n; i++) {
            int count = 1;
            for (int j = i + 1; j < n; j++) {
                if ((long)nums[j] <= (long)nums[i] * k) {
                    count++;
                }
            }
            maxLen = Math.max(maxLen, count);
        }
        return n - maxLen;
    }
}