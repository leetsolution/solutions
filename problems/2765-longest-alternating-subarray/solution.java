class Solution {
    public int alternatingSubarray(int[] nums) {
        int maxLength = -1;
        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                int length = j - i + 1;
                if (length > 1) {
                    boolean alternating = true;
                    for (int k = i + 1; k <= j; k++) {
                        if (nums[k] - nums[k - 1] != Math.pow(-1, k - i)) {
                            alternating = false;
                            break;
                        }
                    }
                    if (alternating) {
                        maxLength = Math.max(maxLength, length);
                    }
                }
            }
        }
        return maxLength;
    }
}