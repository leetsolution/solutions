class Solution {
    public boolean isGood(int[] nums) {
        int n = nums.length;
        int maxVal = 0;
        for (int num : nums) {
            maxVal = Math.max(maxVal, num);
        }

        if (n != maxVal + 1) {
            return false;
        }

        int[] counts = new int[maxVal + 1];
        for (int num : nums) {
            counts[num]++;
        }

        if (counts[maxVal] != 2) {
            return false;
        }

        for (int i = 1; i < maxVal; i++) {
            if (counts[i] != 1) {
                return false;
            }
        }

        return true;
    }
}