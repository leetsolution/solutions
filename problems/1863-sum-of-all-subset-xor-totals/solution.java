class Solution {
    public int subsetXORSum(int[] nums) {
        int n = nums.length;
        int sum = 0;
        for (int i = 0; i < (1 << n); i++) {
            int xor = 0;
            for (int j = 0; j < n; j++) {
                if ((i >> j) % 2 == 1) {
                    xor ^= nums[j];
                }
            }
            sum += xor;
        }
        return sum;
    }
}