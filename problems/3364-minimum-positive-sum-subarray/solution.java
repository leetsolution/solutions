import java.util.List;

class Solution {
    public int minimumSumSubarray(List<Integer> nums, int l, int r) {
        int minSum = Integer.MAX_VALUE;
        boolean found = false;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + l - 1; j < nums.size(); j++) {
                if (j - i + 1 > r) {
                    break;
                }
                int currentSum = 0;
                for (int k = i; k <= j; k++) {
                    currentSum += nums.get(k);
                }
                if (currentSum > 0) {
                    minSum = Math.min(minSum, currentSum);
                    found = true;
                }
            }
        }
        if (found) {
            return minSum;
        } else {
            return -1;
        }
    }
}