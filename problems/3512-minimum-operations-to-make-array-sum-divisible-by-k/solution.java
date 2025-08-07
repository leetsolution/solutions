class Solution {
    public int minOperations(int[] nums, int k) {
        int sum = 0;
        for (int num : nums) {
            sum = (sum + num) % k;
        }
        if (sum == 0) {
            return 0;
        }
        return k - sum;
    }
}