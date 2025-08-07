class Solution {
    public int missingInteger(int[] nums) {
        int n = nums.length;
        int longestPrefixLength = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1] + 1) {
                longestPrefixLength++;
            } else {
                break;
            }
        }

        int prefixSum = 0;
        for (int i = 0; i < longestPrefixLength; i++) {
            prefixSum += nums[i];
        }

        boolean[] present = new boolean[101];
        for (int num : nums) {
            present[num] = true;
        }

        int x = prefixSum;
        while (x <= 100 && present[x]) {
            x++;
        }

        while (true) {
            if (!present[x]) {
                return x;
            }
            x++;
        }
    }
}