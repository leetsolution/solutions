class Solution {
    public int minStartValue(int[] nums) {
        int minSum = 0;
        int currentSum = 0;
        for (int num : nums) {
            currentSum += num;
            minSum = Math.min(minSum, currentSum);
        }
        return Math.max(1, 1 - minSum);
    }
}